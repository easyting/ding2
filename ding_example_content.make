api = 2
core = 7.x

projects[node_export][subdir] = "contrib"
projects[node_export][version] = "3.0"
projects[node_export][patch][] = "http://drupal.org/files/suppress-feature-install-profile-import.patch"
projects[node_export][patch][] = "http://drupal.org/files/check-field.patch"

# Using dev release, as the "stable" version is making errors on install profile.
projects[uuid][subdir] = "contrib"
projects[uuid][download][type] = "git"
projects[uuid][download][url] = "http://git.drupal.org/project/uuid.git"
projects[uuid][download][revision] = "3f4d9fb"

projects[ding_library][type] = "module"
projects[ding_library][download][type] = "git"
projects[ding_library][download][url] = "git@github.com:ding2tal/ding_library.git"
projects[ding_library][download][branch] = "development"

projects[ding_event][type] = "module"
projects[ding_event][download][type] = "git"
projects[ding_event][download][url] = "git@github.com:ding2tal/ding_event.git"
projects[ding_event][download][branch] = "development"

projects[ding_news][type] = "module"
projects[ding_news][download][type] = "git"
projects[ding_news][download][url] = "git@github.com:ding2tal/ding_news.git"
projects[ding_news][download][branch] = "development"

projects[ding_page][type] = "module"
projects[ding_page][download][type] = "git"
projects[ding_page][download][url] = "git@github.com:ding2tal/ding_page.git"
projects[ding_page][download][branch] = "development"

projects[ding_content][type] = "module"
projects[ding_content][download][type] = "git"
projects[ding_content][download][url] = "git@github.com:ding2tal/ding_content.git"
projects[ding_content][download][branch] = "development"

projects[ding_example_content_groups][type] = "module"
projects[ding_example_content_groups][download][type] = "git"
projects[ding_example_content_groups][download][url] = "git@github.com:ding2tal/ding_example_content_groups.git"
projects[ding_example_content_groups][download][branch] = "development"
