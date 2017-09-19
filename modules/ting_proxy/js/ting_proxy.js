/**
 * @file
 * Perform redirect functionality
 */
'use strict';

/**
 * Preprocess url before attach to template.
 */
function tingProxySPTUrlPreprocess(data) {
  var url = document.createElement("a");
  url.href = data;

  var ting_proxy = Drupal.settings.spt.proxy_settings;

  if (ting_proxy.hostnames !== undefined && ting_proxy.hostnames.length > 0) {
    for (var i = 0; i < ting_proxy.hostnames.length; i++) {
      if (url.href.includes(ting_proxy.hostnames[i].hostname) && ting_proxy.hostnames[i].disable_prefix === 0) {
        var regexp = ting_proxy.hostnames[i].expression.regex;
        var replacement = ting_proxy.hostnames[i].expression.replacement;
        url.href = ting_proxy.prefix + url + '&hostname=' + url.hostname;

        if (regexp.length > 0 && replacement.length > 0) {
          url.href = url.replace(new RegExp(regexp), replacement);
        }
      }
    }
  }

  return url;
}
