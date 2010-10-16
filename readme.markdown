# sc2ranks module for drupal

## Usage
1. Make sure you have the profile module enabled.
2. Create two fields for user's to enter character name and character code
data for battle.net, be sure to note the names of these fields.
3. Install and enable the sc2ranks module.
4. Configure permissions to view and administer the sc2ranks module
5. Configure the sc2ranks module @ /admin/settings/sc2ranks be sure to set the
field names you set earlier in the profile configuration panel so sc2ranks module 
knows where to look for a user's character name and code.
6. Check everything is working by visiting a user's profile page that has
set a battle.net character name and id.

### Screenshot
![Sample profile data](http://github.com/ameerkat/sc2ranks-drupal/raw/master/images/readme-sample-profile-data.jpg)

## Theming
You can override theme data by creating your own profile-sc2ranks.tpl.php

Refer to the default profile-sc2ranks.tpl.php for variable data.

## TODO
* Better Theming documentation
* Views integration
