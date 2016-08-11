/**
 * @file
 * Represents functionality which relates to theme.
 */
var ding_mkws_process = {};
(function ($) {

  ding_mkws_process.ProcessDataForNodeWidget = function(data) {
    var variables = {title: "Test title", items: {left: [], right: []}};
    for (var i = 0; i < data.hits.length; i++) {
      var idx = (i % 2) ? 'left' : 'right';
      try {
        var out = {
          title: data.hits[i]['md-title'],
          source: data.hits[i].location[0]['md-bibliofil-url'],
          name: data.hits[i].location[0]['@name'],
        };
        variables.items[idx].push(out);
      }
      catch (e) {}
    }
   return variables;
  };

  $.templates("dingMkwsNodeWidget", "" +
    "<div class='ding-mkws-widget ding-mkws-widget-node'>" +
      "{{if title}}" +
      "<div class='ding-mkws-title'>{{:title}}</div>" +
      "{{/if}}"+
      "<div class='ding-mkws-content'>" +
        "<div class='ding-mkws-left'>" +
          "<ul>{{for items.left}}" +
            "<li>" +
              "<div class='ding-mkws-header'>" +
                "<p class='ding-mkws-source'>" +
                  Drupal.t('Source') +
                "</p>" +
                "<p class='ding-mkws-name'>" +
                  Drupal.t('Title') +
                "</p>" +
              "</div>" +
              "<div class='ding-mkws-values'>" +
                "<a class='ding-mkws-source' href='{{:source}}'>" +
                  '{{:name}}' +
                "</a>" +
                "<p class='ding-mkws-name'>" +
                  '{{:title}}' +
                "</p>" +
              "</div>" +
            "</li>"+
          "{{/for}}</ul>" +
        "</div>" +
        "<div class='ding-mkws-rigt'>" +
          "<ul>{{for items.right}}" +
            "<li>" +
              "<div class='ding-mkws-header'>" +
                "<p class='ding-mkws-source'>" +
                Drupal.t('Source') +
                "</p>" +
                "<p class='ding-mkws-name'>" +
                Drupal.t('Title') +
                "</p>" +
              "</div>" +
              "<div class='ding-mkws-values'>" +
                "<a class='ding-mkws-source'  href='{{:source}}'>" +
                '{{:name}}' +
                "</a>" +
                "<p class='ding-mkws-name'>" +
                '{{:title}}' +
                "</p>" +
              "</div>" +
            "</li>"+
          "{{/for}}</ul>" +
        "</div>" +
      "</div>" +
    "</div>");
})(jQuery);
