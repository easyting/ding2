core = 7.x
api = 2

defaults[projects][subdir] = "contrib"

; Contrib modules
projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.0-beta5"

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc5"

projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.6"

projects[apc][subdir] = "contrib"
projects[apc][version] = "1.0-beta4"

projects[autologout][subdir] = "contrib"
projects[autologout][version] = "4.3"

projects[autosave][subdir] = "contrib"
projects[autosave][version] = "2.2"

projects[block_access][subdir] = "contrib"
projects[block_access][version] = "1.5"

projects[cache_actions][subdir] = "contrib"
projects[cache_actions][version] = "2.0-alpha5"

projects[conditional_styles][subdir] = "contrib"
projects[conditional_styles][version] = "2.2"

projects[cs_adaptive_image][subdir] = "contrib"
projects[cs_adaptive_image][version] = "1.0"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.9"
; Fix regression. See https://www.drupal.org/node/2209775
projects[ctools][patch][] = "https://www.drupal.org/files/issues/ctools-readd_access_callback_params-2209775-24.patch"

projects[date][subdir] = "contrib"
projects[date][version] = "2.8"

; Patch to fix empty order_id. See https://drupal.org/node/2107389
projects[dibs][subdir] = "contrib"
projects[dibs][version] = "1.0"
projects[dibs][patch][] = "http://drupal.org/files/dibs-2107389-2.patch"

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"

; The patch ensures that file upload patch is created on file upload. It normally
; created on settings form save, but as we use feature this do not work.
; See https://www.drupal.org/node/2410241
projects[dynamic_background][subdir] = "contrib"
projects[dynamic_background][version] = "2.0-rc4"
projects[dynamic_background][patch][] = "https://www.drupal.org/files/issues/create_file_path-2410241-1.patch"

projects[eck][subdir] = "contrib"
projects[eck][version] = "2.0-rc7"

projects[email][subdir] = "contrib"
projects[email][version] = "1.3"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.7"

projects[entitycache][subdir] = "contrib"
projects[entitycache][version] = "1.2"
; https://drupal.org/node/2146543, profile 2 blank fields.
projects[entitycache][patch][0] = "http://drupal.org/files/issues/2146543-ensure-entity-inserts-clears-caches.1.patch"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.1"

projects[eu_cookie_compliance][subdir] = "contrib"
projects[eu_cookie_compliance][version] = "1.14"

projects[expire][subdir] = "contrib"
projects[expire][version] = "2.0-rc4"

projects[features][subdir] = "contrib"
projects[features][version] = "2.0"

projects[features_extra][subdir] = "contrib"
projects[features_extra][version] = "1.0-beta1"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.0-alpha8"

projects[fences][type] = "module"
projects[fences][subdir] = "contrib"
projects[fences][version] = "1.0"
projects[fences][patch][0] = "http://drupal.org/files/field_for_wrapper_css_class-1679684-3.patch"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.0-alpha3"

projects[flag][subdir] = "contrib"
projects[flag][version] = "2.2"

projects[fontyourface][subdir] = "contrib"
projects[fontyourface][version] = "2.7"

projects[formblock][type] = "module"
projects[formblock][subdir] = "contrib"
projects[formblock][download][type] = "git"
projects[formblock][download][url] = "http://git.drupal.org/project/formblock.git"
projects[formblock][download][revision] = "2d94c83"

projects[geocoder][subdir] = "contrib"
projects[geocoder][version] = "1.2"

projects[geofield][subdir] = "contrib"
projects[geofield][version] = "1.2"

projects[geophp][subdir] = "contrib"
projects[geophp][version] = "1.7"

projects[globalredirect][subdir] = "contrib"
projects[globalredirect][version] = "1.5"
projects[globalredirect][patch][] = "http://drupal.org/files/language_redirect_view_node-1399506-2.patch"

projects[google_analytics][subdir] = "contrib"
projects[google_analytics][version] = "1.3"

projects[htmlmail][subdir] = "contrib"
projects[htmlmail][version] = "2.65"

projects[honeypot][subdir] = "contrib"
projects[honeypot][version] = "1.21"

projects[image_resize_filter][subdir] = "contrib"
projects[image_resize_filter][version] = "1.14"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha3"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.6"

projects[languageicons][subdir] = "contrib"
projects[languageicons][version] = "1.0"

projects[lazy_pane][subdir] = "contrib"
projects[lazy_pane][version] = "1.2"

projects[leaflet][subdir] = "contrib"
projects[leaflet][version] = "1.1"
; OSM Mapnik is hard-coded to be accessed via http, but some sites may need maps to render under https.
; The patch change code to use headless urls ("//" instead of "http://") for map access..
; Patch from https://www.drupal.org/node/2341015
projects[leaflet][patch][] = https://www.drupal.org/files/issues/leaflet-https_7x_11-2341015-3.patch

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.2"

projects[link][subdir] = "contrib"
projects[link][version] = "1.2"

projects[l10n_update][type] = "module"
projects[l10n_update][subdir] = "contrib"
projects[l10n_update][version] = "1.0"

projects[i18n][subdir] = "contrib"
projects[i18n][version] = "1.11"

projects[manualcrop][subdir] = "contrib"
projects[manualcrop][version] = "1.5"

projects[mailsystem][subdir] = "contrib"
projects[mailsystem][version] = "2.34"

projects[maintenance_mode_api][subdir] = "contrib"
projects[maintenance_mode_api][version] = "1.0-beta1"

; This version of media is tested to work with both images and videos.
projects[media][type] = "module"
projects[media][subdir] = "contrib"
projects[media][download][type] = "git"
projects[media][download][url] = "http://git.drupal.org/project/media.git"
projects[media][download][revision] = "c3cda2b"
; Fixed issue where "insert" fails, see https://www.drupal.org/node/2184475.
projects[media][patch][] = "https://www.drupal.org/files/issues/media_popup_trigger_some_js-2184475-6.patch"

projects[media_vimeo][subdir] = "contrib"
projects[media_vimeo][version] = "2.0-rc1"

projects[media_youtube][type] = "module"
projects[media_youtube][subdir] = "contrib"
projects[media_youtube][download][type] = "git"
projects[media_youtube][download][url] = "http://git.drupal.org/project/media_youtube.git"
projects[media_youtube][download][revision] = "ca46aba"
projects[media_youtube][patch][] = "http://drupal.org/files/issues/provide-access-wrapper-1823376-6.patch"

projects[memcache][subdir] = "contrib"
projects[memcache][version] = "1.5"

; Get a this special version that has support for features export.
projects[menu_block][type] = "module"
projects[menu_block][subdir] = "contrib"
projects[menu_block][download][type] = "git"
projects[menu_block][download][url] = "http://git.drupal.org/project/menu_block.git"
projects[menu_block][download][revision] = "32ab1cf08b729c93302455d67dd05f64ad2fc056"
projects[menu_block][patch][0] = "http://drupal.org/files/menu_block-ctools-693302-96.patch"

projects[menu_breadcrumb][subdir] = "contrib"
projects[menu_breadcrumb][version] = "1.5"

projects[menu_position][subdir] = "contrib"
projects[menu_position][version] = "1.1"

projects[message][subdir] = "contrib"
projects[message][version] = "1.10"

projects[metatag][subdir] = "contrib"
projects[metatag][version] "1.10"

projects[mmeu][subdir] = "contrib"
projects[mmeu][version] = "1.0"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "1.8"

; NanoSOAP is currently not placed in contrib at this was not the case
; when using recursive make files.
projects[nanosoap][subdir] = "contrib"
projects[nanosoap][version] = "1.0"
projects[nanosoap][patch][] = "http://drupal.org/files/nanosoap-curloptions-1943732.patch"

projects[nodequeue][subdir] = "contrib"
projects[nodequeue][version] = "2.0-beta1"

projects[node_clone][subdir] = "contrib"
projects[node_clone][version] = "1.0-rc2"

projects[node_export][subdir] = "contrib"
projects[node_export][version] = "3.0"
projects[node_export][patch][] = "http://drupal.org/files/suppress-feature-install-profile-import.patch"
projects[node_export][patch][] = "http://drupal.org/files/check-field.patch"

projects[oembed][subdir] = "contrib"
projects[oembed][version] = "1.0-rc2"
; Remove hook_system_info_alter() to allow installing modules depending on oembed, after oembed is installed.
projects[oembed][patch][] = "http://www.drupal.org/files/issues/oembed-remove_hook_sytem_info_alter-2502817-1.patch"
; Fix PHP Fatal error: Unsupported operand types. See https://www.drupal.org/node/2021015
projects[oembed][patch][] = "https://www.drupal.org/files/oembed-2021015-1.patch"

projects[og][subdir] = "contrib"
projects[og][version] = "2.7"
projects[og][patch][] = "https://www.drupal.org/files/issues/entityreference_fields_do_not_validate-2249261-10.patch"
; Fix using organic groups for relationships in views
; https://www.drupal.org/node/1890370
projects[og][patch][] = "https://www.drupal.org/files/issues/add-gid-to-relationship-field-1890370-34.patch"

projects[og_menu][subdir] = "contrib"
projects[og_menu][version] = "3.0-rc5"
; Fixes JavaScript menu selection in edit node forms.
projects[og_menu][patch][0] = "http://drupal.org/files/issues/selector_not_found-2276951-2.patch"

projects[opening_hours][subdir] = "contrib"
projects[opening_hours][version] = "1.6"
; Adjust granularity to one minte.
; https://www.drupal.org/node/2381127
projects[opening_hours][patch][] = "http://www.drupal.org/files/issues/Issue620-single-minute-opening-hours.patch"
; Support series longer than a year.
; https://www.drupal.org/node/2194867
projects[opening_hours][patch][] = "https://www.drupal.org/files/issues/opening_hours-2194867-D7.patch"
; Add "hide if empty" option to field settings.
; https://www.drupal.org/node/2820005
projects[opening_hours][patch][] = "https://www.drupal.org/files/issues/opening-hours-2820005-hide-field-if-empty.patch"

projects[override_node_options][subdir] = "contrib"
projects[override_node_options][version] = "1.13"

projects[pagepreview][subdir] = "contrib"
projects[pagepreview][version] = "1.0-alpha1"

projects[panels][subdir] = "contrib"
projects[panels][version] = "3.4"
; https://www.drupal.org/node/1179034 Enable translation of panels title.
; There's an i18n integration module but it doesn't work with tiltes and that's all we need.
; See link above for more information.
projects[panels][patch][0] = "https://www.drupal.org/files/issues/1179034-106.patch"

projects[panels_breadcrumbs][subdir] = "contrib"
projects[panels_breadcrumbs][version] = "2.1"

projects[panels_everywhere][subdir] = "contrib"
projects[panels_everywhere][version] = "1.0-rc1"
projects[panels_everywhere][type] = "module"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.2"

projects[pm_existing_pages][subdir] = "contrib"
projects[pm_existing_pages][version] = "1.4"

projects[proj4js][subdir] = "contrib"
projects[proj4js][version] = "1.2"

projects[profile2][subdir] = "contrib"
projects[profile2][version] = "1.3"

projects[realname][subdir] = "contrib"
projects[realname][version] = "1.2"

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc3"

projects[relation][subdir] = "contrib"
projects[relation][version] = "1.0"

projects[role_delegation][subdir] = "contrib"
projects[role_delegation][version] = "1.1"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.7"

projects[scheduler][subdir] = "contrib"
projects[scheduler][version] = "1.2"
; Suppress validation when deleting node.
projects[scheduler][patch][] = "https://www.drupal.org/files/issues/validation_interferes-1.2-2627370-4.patch"

; Patched with "Secure Permissions fails with features and multilingual"
projects[secure_permissions][type] = "module"
projects[secure_permissions][subdir] = "contrib"
projects[secure_permissions][download][type] = "git"
projects[secure_permissions][download][url] = "http://git.drupal.org/project/secure_permissions.git"
projects[secure_permissions][download][revision] = "ef5eec5"
projects[secure_permissions][patch][] = "http://drupal.org/files/issues/2188491-features-multilingual-2.patch"

projects[services][subdir] = "contrib"
projects[services][version] = "3.14"

projects[services_views][subdir] = "contrib"
projects[services_views][version] = "1.1"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.16"
; Fix search_api warnings and notices. should be removed when upgrading to 1.17.
projects[search_api][patch][] = "https://www.drupal.org/files/issues/2563793-9--multiple_types_issues.patch"

projects[search_api_multi][subdir] = "contrib"
projects[search_api_multi][version] = "1.3"
; Fix incompatibility with Multiple types indexes
; https://www.drupal.org/node/2580975
projects[search_api_multi][patch][] = "https://www.drupal.org/files/issues/2580975-2--fix_multi_type_index_incompatibilities.patch"

projects[search_api_db][subdir] = "contrib"
projects[search_api_db][version] = "1.5"

projects[similarterms][subdir] = "contrib"
projects[similarterms][version] = "2.3"

projects[sslproxy][subdir] = "contrib"
projects[sslproxy][version] = "1.0"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[tipsy][subdir] = "contrib"
projects[tipsy][version] = "1.0-rc1"

projects[token][subdir] = "contrib"
projects[token][version] = "1.6"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.2"

; Using dev release, as the "stable" version is making errors in the install profile.
projects[uuid][subdir] = "contrib"
projects[uuid][download][type] = "git"
projects[uuid][download][url] = "http://git.drupal.org/project/uuid.git"
projects[uuid][download][revision] = "3f4d9fb"

projects[variable][subdir] = "contrib"
projects[variable][version] = "2.5"

projects[varnish][subdir] = "contrib"
projects[varnish][version] = "1.0-beta3"
projects[varnish][patch][0] = "http://drupal.org/files/issues/notification_level_settings-2169271-3.patch"
; Fixes "Connection reset by peer" on large purge list by batching paths, https://www.drupal.org/node/1481136
projects[varnish][patch][] = "https://www.drupal.org/files/issues/varnish_purge_limit-1481136-11_1.patch"
; Fixes missing leading slash from ban URLs, https://www.drupal.org/node/2340829
projects[varnish][patch][] = "https://www.drupal.org/files/issues/varnish-leave_base_path_in_urls-2340829-26.patch"

projects[virtual_field][subdir] = "contrib"
projects[virtual_field][version] = "1.2"

projects[views][subdir] = "contrib"
projects[views][version] = "3.8"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.2"

projects[views_responsive_grid][subdir] = "contrib"
projects[views_responsive_grid][version] = "1.3"

; Development version where the "unpublished" status have been fixed on the content edit page.
projects[view_unpublished][subdir] = "contrib"
projects[view_unpublished][download][type] = "git"
projects[view_unpublished][download][url] = "http://git.drupal.org/project/view_unpublished.git"
projects[view_unpublished][download][revision] = "e9df1d3"

projects[webform][subdir] = "contrib"
projects[webform][version] = "4.10"

projects[workbench][subdir] = "contrib"
projects[workbench][version] = "1.2"

projects[workflow][subdir] = "contrib"
projects[workflow][version] = "2.5"
projects[workflow][patch][] = "http://www.drupal.org/files/issues/features_import-2484297-10.patch"
; Prevent fatal errors on cron when using Scheduler, https://www.drupal.org/node/2499193.
projects[workflow][patch][] = "https://www.drupal.org/files/issues/workflow-php_fatal_error_call-2499193-7-2.5.patch"

; This revision support the CKEditor 4.x, and can be used until a new version is tagged.
projects[wysiwyg][type] = "module"
projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][download][type] = "git"
projects[wysiwyg][download][url] = "http://git.drupal.org/project/wysiwyg.git"
projects[wysiwyg][download][revision] = "7981731f4f3db2f932419499d2ec13a073e9b88f"

projects[ask_vopros][type] = "module"
projects[ask_vopros][subdir] = "contrib"
projects[ask_vopros][download][type] = "git"
projects[ask_vopros][download][url] = "git@github.com:vopros-dk/ask_vopros.git"
projects[ask_vopros][download][tag] = "1.5"

projects[xautoload][subdir] = "contrib"
projects[xautoload][version] = "5.7"

; Libraries
libraries[bpi-client][destination] = "modules/bpi/lib"
libraries[bpi-client][download][type] = "git"
libraries[bpi-client][download][url] = "http://github.com/ding2/bpi-client.git"
libraries[bpi-client][download][branch] = "master"

libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.7/ckeditor_4.4.7_full.zip
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/1.4.2/chosen_v1.4.2.zip"
libraries[chosen][destination] = "libraries"

libraries[guzzle][download][type] = "git"
libraries[guzzle][download][url] = "https://github.com/guzzle/guzzle.git"
libraries[guzzle][download][tag] = "6.2.2"
libraries[guzzle][destination] = "libraries"

libraries[http-message][download][type] = "git"
libraries[http-message][download][url] = "https://github.com/php-fig/http-message.git"
libraries[http-message][download][tag] = "1.0.1"
libraries[http-message][destination] = "libraries"

libraries[leaflet][download][type] = "get"
libraries[leaflet][download][url] = "http://cdn.leafletjs.com/downloads/leaflet-0.7.3.zip"
libraries[leaflet][directory_name] = "leaflet"
libraries[leaflet][destination] = "libraries"

libraries[profiler][download][type] = "git"
libraries[profiler][download][url] = "http://git.drupal.org/project/profiler.git"
libraries[profiler][download][branch] = "7.x-2.0-beta1"
; https://drupal.org/node/1328796, keep dependency order of base profile.
libraries[profiler][patch][0] = "http://drupal.org/files/profiler-reverse.patch"

libraries[promises][download][type] = "git"
libraries[promises][download][url] = "https://github.com/guzzle/promises.git"
libraries[promises][download][tag] = "1.2.0"
libraries[promises][destination] = "libraries"

libraries[psr7][download][type] = "git"
libraries[psr7][download][url] = "https://github.com/guzzle/psr7.git"
libraries[psr7][download][tag] = "1.3.1"
libraries[psr7][destination] = "libraries"

libraries[ting-client][download][type] = "git"
libraries[ting-client][download][url] = "http://github.com/ding2/ting-client.git"
libraries[ting-client][download][branch] = "master"
libraries[ting-client][destination] = "modules/ting/lib"

libraries[zen-grids][download][type] = "git"
libraries[zen-grids][download][url] = "https://github.com/JohnAlbin/zen-grids.git"
libraries[zen-grids][download][tag] = "1.4"
libraries[zen-grids][destination] = "libraries"

libraries[jquery.imgareaselect][download][type] = "get"
libraries[jquery.imgareaselect][download][url] =  http://odyniec.net/projects/imgareaselect/jquery.imgareaselect-0.9.10.zip
libraries[jquery.imgareaselect][directory_name] = "jquery.imgareaselect"
libraries[jquery.imgareaselect][destination] = "libraries"

libraries[jquery.imagesloaded][download][type] = "get"
libraries[jquery.imagesloaded][download][url] = https://github.com/desandro/imagesloaded/archive/v2.1.2.tar.gz
libraries[jquery.imagesloaded][directory_name] = "jquery.imagesloaded"
libraries[jquery.imagesloaded][destination] = "libraries"

libraries[jquery-ui-carousel][download][type] = "get"
libraries[jquery-ui-carousel][download][url] = "https://github.com/richardscarrott/jquery-ui-carousel/archive/1.0.1.zip"
libraries[jquery-ui-carousel][directory_name] = "jquery-ui-carousel"
libraries[jquery-ui-carousel][destination] = "libraries"

; Vejlebib additions
; Contrib
projects[chr][subdir] = "contrib"
projects[chr][version] = "1.8"

projects[d3][subdir] = "contrib"
projects[d3][version] = "1.x-dev"

projects[environment_indicator][subdir] = "contrib"
projects[environment_indicator][version] = "2.8"

projects[entityqueue][subdir] = "contrib"
projects[entityqueue][version] = "1.1"

projects[features_override][subdir] = "contrib"
projects[features_override][version] = 2.0-rc2

projects[gtranslate][subdir] = "contrib"
projects[gtranslate][version] = "1.14"

projects[mailchimp][subdir] = "contrib"
projects[mailchimp][version] = "2.12"

projects[panelizer][subdir] = "contrib"
projects[panelizer][version] = "3.1"

; TODO: update to newest version and remove patches accordingly.
projects[wayf_dk_login][type] = "module"
projects[wayf_dk_login][subdir] = "contrib"
projects[wayf_dk_login][download][type] = "git"
projects[wayf_dk_login][download][url] = "http://git.drupal.org/project/wayf_dk_login.git"
projects[wayf_dk_login][download][revision] = "5020f26"
; Fix index errors in php 5.4 (https://www.drupal.org/node/2414137).
projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/fix_index_errors-2414137-1.patch"
; Allow other modules to take over user creation process (https://www.drupal.org/node/2414173).
projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/allow_other_module_to_create_users-2414173-1.patch"
; Giver other modules change to alter login data (https://www.drupal.org/node/2414927).
projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/auth_alters-2414927-1.patch"
; Add support for metadata export (https://www.drupal.org/node/2415975).
projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/generate-sp-metadate-2415975-1.patch"
; Change link to use render array (https://www.drupal.org/node/2416347).
projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/render-array-for-link-2416347-1.patch"
; Add pre logout hook support (https://www.drupal.org/node/2427193).
projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/pre-logout-2427193-1.patch"
; Add scoping support (https://www.drupal.org/node/2428847).
projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/wayf_dk_scoping_support-2428847-2.patch"
; Change in metadata end-point and struture (https://www.drupal.org/node/2734715).
;projects[wayf_dk_login][patch][] = "https://www.drupal.org/files/issues/metadata_endpoint_2728389-3.patch"

; Libraries
libraries[d3][download][type] = "get"
libraries[d3][download][url] = "https://github.com/d3/d3/releases/download/v3.5.17/d3.zip"
libraries[d3][directory_name] = "d3"
libraries[d3][destination] = "libraries"

libraries[mailchimp][download][type] = "get"
libraries[mailchimp][download][url] = "http://apidocs.mailchimp.com/api/downloads/mailchimp-api-class.zip"
libraries[mailchimp][directory_name] = "mailchimp"
libraries[mailchimp][destination] = "libraries"

; External modules that we still have to keep separate from the main repo
projects[ding_zerohit_form][type] = "module"
projects[ding_zerohit_form][download][type] = "git"
projects[ding_zerohit_form][download][url] = "git@github.com:vejlebib/ding_zerohit_form.git"
projects[ding_zerohit_form][download][branch] = "7.x-1.x"
projects[ding_zerohit_form][subdir] = "vejlebib_modules"

projects[ding_opening_hours][type] = "module"
projects[ding_opening_hours][download][type] = "git"
projects[ding_opening_hours][download][url] = "git@github.com:vejlebib/ding_opening_hours.git"
projects[ding_opening_hours][download][branch] = "master"
projects[ding_opening_hours][subdir] = "vejlebib_modules"

projects[ding_eresource][type] = "module"
projects[ding_eresource][download][type] = "git"
projects[ding_eresource][download][url] = "git@github.com:vejlebib/ding_eresource.git"
projects[ding_eresource][download][branch] = "master"
projects[ding_eresource][subdir] = "vejlebib_modules"

projects[ding_redia_bapp][type] = "module"
projects[ding_redia_bapp][download][type] = "git"
projects[ding_redia_bapp][download][url] = "git@github.com:vejlebib/ding_redia_bapp.git"
projects[ding_redia_bapp][download][branch] = "7.x-1.x"
projects[ding_redia_bapp][subdir] = "vejlebib_modules"

projects[ding_wagnerguide][type] = "module"
projects[ding_wagnerguide][download][type] = "git"
projects[ding_wagnerguide][download][url] = "git@github.com:vejlebib/ding_wagnerguide.git"
projects[ding_wagnerguide][download][branch] = "7.x-1.x"
projects[ding_wagnerguide][subdir] = "vejlebib_modules"

projects[ting_covers_plus][type] = "module"
projects[ting_covers_plus][download][type] = "git"
projects[ting_covers_plus][download][url] = "git@github.com:vejlebib/ting_covers_plus.git"
projects[ting_covers_plus][download][branch] = "7.x-1.x"
projects[ting_covers_plus][subdir] = "vejlebib_modules"

projects[ting_visual_relation][type] = "module"
projects[ting_visual_relation][download][type] = "git"
projects[ting_visual_relation][download][url] = "git@github.com:vejlebib/ting_visual_relation.git"
projects[ting_visual_relation][download][branch] = "master"
projects[ting_visual_relation][subdir] = "vejlebib_modules"

projects[ting_marc][type] = "module"
projects[ting_marc][download][type] = "git"
projects[ting_marc][download][url] = "git@github.com:easyddb/ting_marc"
projects[ting_marc][download][branch] = "master"
projects[ting_marc][subdir] = "vejlebib_modules"

projects[ding_wayf_dk][type] = "module"
projects[ding_wayf_dk][download][type] = "git"
projects[ding_wayf_dk][download][url] = "git@github.com:vejlebib/ding_wayf_dk.git"
projects[ding_wayf_dk][download][branch] = "vejlebib"
projects[ding_wayf_dk][subdir] = "vejlebib_modules"

projects[ting_field_search][type] = "module"
projects[ting_field_search][download][type] = "git"
projects[ting_field_search][download][url] = "git@github.com:vejlebib/ting_field_search.git"
projects[ting_field_search][download][branch] = "master"
projects[ting_field_search][subdir] = "vejlebib_modules"
