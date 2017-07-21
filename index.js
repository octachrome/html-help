var HtmlHelpNative = require('bindings')('HtmlHelpNative');

function HtmlHelp(chmPath) {
    if (!chmPath) {
        throw new Error('Must provide the path to the CHM file');
    }
    this.chmPath = chmPath;
}

HtmlHelp.prototype.displayIndex = function (keyword) {
    HtmlHelpNative.displayIndex(this.chmPath, keyword);
}

HtmlHelp.prototype.displayTopic = function (topic) {
    HtmlHelpNative.displayTopic(this.chmPath, topic);
}

module.exports = HtmlHelp;
