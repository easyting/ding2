// Set up namespace and some state.
var ding_mkws = {
  // Variables
  active: false,
  pz2: null,
  totalRec: 0,
  pagerRange: 6,
  settings: {},
  defaultState: {
    page: 1,
    perpage: 20,
    sort: 'relevance',
    query: 'abba',
    recid: null
  },
  state: {},
};

// Wrapper for jQuery
(function ($) {
  ding_mkws.settings = Drupal.settings.ding_mkws;

  ding_mkws.pz2Init = function () {
    if (ding_mkws.state.query) {
      ding_mkws.search();
    }
  };

  ding_mkws.pz2Show = function (event, data) {
  }

  ding_mkws.pz2Status = function (event, data) {
  };

  ding_mkws.pz2Term = function (event, data) {
  };

  ding_mkws.pz2Record = function (event, data) {
    clearTimeout(ding_mkws.pz2.showTimer);
    clearTimeout(ding_mkws.pz2.recordTimer);
  };

  ding_mkws.search = function () {
    var filter = null;
    ding_mkws.pz2.search(ding_mkws.state.query, ding_mkws.state.perpage, ding_mkws.sort, filter, null, {limit: null});
    ding_mkws.active = true;
  };

  ding_mkws.auth = function (successCb, failCb) {
    var user = ding_mkws.settings.user;
    var password = ding_mkws.settings.password;
    var params = {};
    params['command'] = 'auth';
    if (user && password) {
      params['action'] = 'login';
      params['username'] = user;
      params['password'] = password;
    }
    var authReq = new pzHttpRequest(ding_mkws.settings.proxy,
      function (err) {
        alert(1);
        //@todo add some logic in case when authentication failed.
      }
    );
    authReq.get(params,
      function (data) {
        var s = data.getElementsByTagName('status');
        if (s.length && Element_getTextContent(s[0]) == "OK") {
          ding_mkws.pz2Init();
          if (typeof successCb == "function") successCb();
        } else {
          if (typeof failCb == "function") failCb();
          else alert(Drupal.t("Failed to authenticate against the metasearch gateway"));
        }
      }
    );
  };

  ding_mkws.init = function () {
    $(document).bind('ding_mkws.onrecord', ding_mkws.pz2Record);
    $(document).bind('ding_mkws.oninit', ding_mkws.pz2Init);

    var pz2Params = {
      "pazpar2path": ding_mkws.settings.proxy,
      "usesessions": false,
      "autoInit": false,
      "showtime": 500,
      "onshow": function (data) {
      },
      "oninit": function () {
        $(document).trigger('ding_mkws.oninit');
      },
      "onstat": function (data) {
      },
      "onterm": function (data) {
      },
      "onrecord": function (data) {
        $(document).trigger('ding_mkws.onrecord', [data]);
      },
    };
    ding_mkws.pz2 = new pz2(pz2Params);
    ding_mkws.pz2.showFastCount = 1;
    ding_mkws.state = $.extend({}, ding_mkws.defaultState, Drupal.settings.ding_mkws.state);
    ding_mkws.auth();
  };

  $(document).ready(function () {
    ding_mkws.init();
  });
})(jQuery);
