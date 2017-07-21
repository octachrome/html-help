#define UNICODE

#include <nan.h>
#include <Htmlhelp.h>
#include <iostream>

void HtmlHelpWithOptionalString(UINT command, const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.Length() < 1) {
    Nan::ThrowTypeError("Must provide the path to the CHM file");
    return;
  }
  if (!info[0]->IsString()) {
    Nan::ThrowTypeError("Path to the CHM file must be a string");
    return;
  }
  v8::String::Value chmPath(info[0]->ToString());

  if (info.Length() > 1 && !info[1]->IsNull() && !info[1]->IsUndefined()) {
    if (!info[1]->IsString()) {
      Nan::ThrowTypeError("Second argument must be a string");
      return;
    }
    v8::String::Value keyword(info[1]->ToString());
    HtmlHelp(NULL, (LPCWSTR) *chmPath, command, (DWORD_PTR) *keyword);
  }
  else {
    HtmlHelp(NULL, (LPCWSTR) *chmPath, command, NULL);
  }
}

void DisplayIndex(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  HtmlHelpWithOptionalString(HH_DISPLAY_INDEX, info);
}

void DisplayTopic(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  HtmlHelpWithOptionalString(HH_DISPLAY_TOPIC, info);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("displayIndex").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(DisplayIndex)->GetFunction());
  exports->Set(Nan::New("displayTopic").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(DisplayTopic)->GetFunction());
}

NODE_MODULE(HtmlHelpNative, Init)
