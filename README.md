html-help
=========

`html-help` is a really simple interface to the [HtmlHelp](https://msdn.microsoft.com/en-us/library/windows/desktop/ms670172%28v=vs.85%29.aspx)
Windows API function.

At the moment it only supports the `HH_DISPLAY_TOPIC` and `HH_DISPLAY_INDEX` commands.

Usage:

    var HtmlHelp = require('html-help');
    var hh = new HtmlHelp('my_help_file.chm');
    hh.displayTopic('some/topic.htm');
    hh.displayIndex('an optional search term');
