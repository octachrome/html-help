{
  "targets": [
    {
      "target_name": "HtmlHelpNative",
      "sources": [ "HtmlHelpNative.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "libraries": [
        "htmlhelp.lib"
      ]
    }
  ]
}
