<?php
/**
 * Custom handlers
 */
function sc2ranks_views_handlers() {
	return array(
		'info' => array(
			'path' => drupal_get_path('module', 'sc2ranks') . '/includes',
		),
		'handlers' => array(
			'sc2ranks_handler_field_league' => array(
				'parent' => 'views_handler_field',
			),
			'sc2ranks_handler_field_fav_race' => array(
				'parent' => 'views_handler_field',
			),
		),	
	);
}

/**
 * Implementation of hook_views_data
 * @author Ameer Ayoub <ameer.ayoub@gmail.com>
 *
 * @todo Implement custom nonfields for profile links
 * @todo Implement custom styling for ranking and races
 * @todo Provide a default player listing view
 */
function sc2ranks_views_data() {
	// Define the group for identification in the UI
	$data['cache_sc2ranks']['table']['group'] = t('sc2ranks');
	
	$data['cache_sc2ranks']['table']['base'] = array(
		'fields' 	=> 'uid',
		'title' 	=> t('sc2ranks player data'),
		'help' 		=> t("table containing sc2ranks player data (cached) related to users in the system."),
	);
	
	// Create the relationship with the user tables
	$data['cache_sc2ranks']['table']['join'] = array(
		'users' => array(
			'left_field' => 'uid',
			'field' => 'uid',
		),
	);
	
	$data['cache_sc2ranks']['uid'] = array(
		'title' => t('Associated user'),
		'help'	=> t("The user associated with this information"),
		'relationship' => array(
			'base' => 'users',
			'field' => 'uid',
			'handler' => 'views_handler_relationship',
			'label' => t("Associated user"),
		),
	);
	
	$data['cache_sc2ranks']['character_name'] = array(
		'title' 	=> t("Battle.Net Character Name"),
		'help'		=> t("Battle.Net Character Name associated with the user."),
		'field'		=> array(
			'handler'	=> 'views_handler_field',
			'click sortable' => TRUE,
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_string',
		),
		'argument' => array(
			'handler' => 'views_handler_argument_string',
		),
	);
	
	$data['cache_sc2ranks']['character_code'] = array(
		'title' 	=> t("Battle.Net Character Code"),
		'help'		=> t("Battle.Net Character Code associated with the user."),
		'field'		=> array(
			'handler'	=> 'views_handler_field',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_string',
		),
		'argument' => array(
			'handler' => 'views_handler_argument_string',
		),
	);
	
	$data['cache_sc2ranks']['league'] = array(
		'title' 	=> t("League"),
		'help'		=> t("The 1v1 ranked league of the player."),
		'field'		=> array(
			'handler'	=> 'sc2ranks_handler_field_league'
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_string',
		),
		'argument' => array(
			'handler' => 'views_handler_argument_string',
		),
	);
	
	$data['cache_sc2ranks']['points'] = array(
		'title' 	=> t("Points"),
		'help'		=> t("The 1v1 ranked league points of the player."),
		'field'		=> array(
			'handler'	=> 'views_handler_field_numeric',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_numeric',
		),
	);
	
	$data['cache_sc2ranks']['division'] = array(
		'title' 	=> t("Division Name"),
		'help'		=> t("The 1v1 league division name."),
		'field'		=> array(
			'handler'	=> 'views_handler_field',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_string',
		),
		'argument' => array(
			'handler' => 'views_handler_argument_string',
		),
	);
	
	
	$data['cache_sc2ranks']['wins'] = array(
		'title'		=> t("Wins"),
		'help'		=> t("Total number of wins for this player on ranked battle.net games"),
		'field'		=> array(
			"handler"	=> "views_handler_field_numeric",
			"click sortable" => TRUE,
		),
		"filter" => array(
			"handler" => "views_handler_filter_numeric",
		),
		"sort" => array(
			"handler" => "views_handler_sort",
		),
	);
	
	$data['cache_sc2ranks']['losses'] = array(
		'title'		=> t("Losses"),
		'help'		=> t("Total number of losses for this player on ranked battle.net games"),
		'field'		=> array(
			"handler"	=> "views_handler_field_numeric",
			"click sortable" => TRUE,
		),
		"filter" => array(
			"handler" => "views_handler_filter_numeric",
		),
		"sort" => array(
			"handler" => "views_handler_sort",
		),
	);
	
	$data['cache_sc2ranks']['fav_race'] = array(
		'title'		=> t("Favorite Race"),
		'help'		=> t("Most played race of this player"),
		'field'		=> array(
			"handler"	=> "sc2ranks_handler_field_fav_race",
			"click sortable" => TRUE,
		),
		"filter" => array(
			"handler" => "views_handler_filter_string",
		),
		"sort" => array(
			"handler" => "views_handler_sort",
		),
		'argument' => array(
			'handler' => 'views_handler_argument_string',
		),
	);
	
	$data['cache_sc2ranks']['bnet_id'] = array(
		'title'		=> t("Battle.Net Profile Id"),
		'help'		=> t("The players bnet id."),
		'field'		=> array(
			"handler"	=> "views_handler_field",
			"click sortable" => TRUE,
		),
		"filter" => array(
			"handler" => "views_handler_filter_numeric",
		),
		"sort" => array(
			"handler" => "views_handler_sort",
		),
	);
	
	return $data;
}

/**
 * Default View
 */
function sc2ranks_views_default_views() {
	$view = new view;
	$view->name = 'sc2ranks_player_listing';
	$view->description = 'Player listing using player stats from sc2ranks module.';
	$view->tag = 'sc2ranks';
	$view->view_php = '';
	$view->base_table = 'cache_sc2ranks';
	$view->is_cacheable = FALSE;
	$view->api_version = 2;
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	$handler = $view->new_display('default', 'Defaults', 'default');
	$handler->override_option('relationships', array(
	  'uid' => array(
		'label' => 'Associated user',
		'required' => 0,
		'id' => 'uid',
		'table' => 'cache_sc2ranks',
		'field' => 'uid',
		'relationship' => 'none',
	  ),
	));
	$handler->override_option('fields', array(
	  'name' => array(
		'label' => 'User',
		'alter' => array(
		  'alter_text' => 0,
		  'text' => '',
		  'make_link' => 0,
		  'path' => '',
		  'link_class' => '',
		  'alt' => '',
		  'prefix' => '',
		  'suffix' => '',
		  'target' => '',
		  'help' => '',
		  'trim' => 0,
		  'max_length' => '',
		  'word_boundary' => 1,
		  'ellipsis' => 1,
		  'html' => 0,
		  'strip_tags' => 0,
		),
		'empty' => '',
		'hide_empty' => 0,
		'empty_zero' => 0,
		'link_to_user' => 1,
		'overwrite_anonymous' => 0,
		'anonymous_text' => '',
		'exclude' => 0,
		'id' => 'name',
		'table' => 'users',
		'field' => 'name',
		'relationship' => 'uid',
	  ),
	  'character_name' => array(
		'label' => 'Battle.Net Character Name',
		'alter' => array(
		  'alter_text' => 0,
		  'text' => '',
		  'make_link' => 0,
		  'path' => '',
		  'link_class' => '',
		  'alt' => '',
		  'prefix' => '',
		  'suffix' => '',
		  'target' => '',
		  'help' => '',
		  'trim' => 0,
		  'max_length' => '',
		  'word_boundary' => 1,
		  'ellipsis' => 1,
		  'html' => 0,
		  'strip_tags' => 0,
		),
		'empty' => '',
		'hide_empty' => 0,
		'empty_zero' => 0,
		'exclude' => 1,
		'id' => 'character_name',
		'table' => 'cache_sc2ranks',
		'field' => 'character_name',
		'relationship' => 'none',
	  ),
	  'character_code' => array(
		'label' => 'Battle.Net Character',
		'alter' => array(
		  'alter_text' => 1,
		  'text' => '[character_name]#[character_code]',
		  'make_link' => 0,
		  'path' => '',
		  'link_class' => '',
		  'alt' => '',
		  'prefix' => '',
		  'suffix' => '',
		  'target' => '',
		  'help' => '',
		  'trim' => 0,
		  'max_length' => '',
		  'word_boundary' => 1,
		  'ellipsis' => 1,
		  'html' => 0,
		  'strip_tags' => 0,
		),
		'empty' => '',
		'hide_empty' => 0,
		'empty_zero' => 0,
		'exclude' => 0,
		'id' => 'character_code',
		'table' => 'cache_sc2ranks',
		'field' => 'character_code',
		'relationship' => 'none',
	  ),
	  'division' => array(
		'id' => 'division',
		'table' => 'cache_sc2ranks',
		'field' => 'division',
	  ),
	  'fav_race' => array(
		'id' => 'fav_race',
		'table' => 'cache_sc2ranks',
		'field' => 'fav_race',
	  ),
	  'league' => array(
		'id' => 'league',
		'table' => 'cache_sc2ranks',
		'field' => 'league',
	  ),
	  'wins' => array(
		'id' => 'wins',
		'table' => 'cache_sc2ranks',
		'field' => 'wins',
	  ),
	  'losses' => array(
		'id' => 'losses',
		'table' => 'cache_sc2ranks',
		'field' => 'losses',
	  ),
	  'points' => array(
		'id' => 'points',
		'table' => 'cache_sc2ranks',
		'field' => 'points',
	  ),
	));
	$handler->override_option('access', array(
	  'type' => 'none',
	));
	$handler->override_option('cache', array(
	  'type' => 'none',
	));
	$handler->override_option('footer', 'Data provided by <a href="http://sc2ranks.com/">sc2ranks.com</a>');
	$handler->override_option('footer_format', '1');
	$handler->override_option('footer_empty', 0);
	$handler->override_option('items_per_page', 50);
	$handler->override_option('style_plugin', 'table');
	$handler->override_option('style_options', array(
	  'grouping' => '',
	  'override' => 1,
	  'sticky' => 0,
	  'order' => 'asc',
	  'columns' => array(
		'character_name' => 'character_name',
		'wins' => 'wins',
		'name' => 'name',
		'character_code' => 'character_code',
		'bnet_id' => 'bnet_id',
		'division' => 'division',
		'fav_race' => 'fav_race',
		'league' => 'league',
		'losses' => 'losses',
		'points' => 'points',
	  ),
	  'info' => array(
		'character_name' => array(
		  'sortable' => 0,
		  'separator' => '',
		),
		'wins' => array(
		  'sortable' => 0,
		  'separator' => '',
		),
		'name' => array(
		  'sortable' => 0,
		  'separator' => '',
		),
		'character_code' => array(
		  'separator' => '',
		),
		'bnet_id' => array(
		  'sortable' => 0,
		  'separator' => '',
		),
		'division' => array(
		  'separator' => '',
		),
		'fav_race' => array(
		  'sortable' => 0,
		  'separator' => '',
		),
		'league' => array(
		  'separator' => '',
		),
		'losses' => array(
		  'sortable' => 0,
		  'separator' => '',
		),
		'points' => array(
		  'separator' => '',
		),
	  ),
	  'default' => '-1',
	));
	$handler = $view->new_display('page', 'Page', 'page_1');
	$handler->override_option('path', 'sc2ranks/player_listing');
	$handler->override_option('menu', array(
	  'type' => 'none',
	  'title' => '',
	  'description' => '',
	  'weight' => 0,
	  'name' => 'navigation',
	));
	$handler->override_option('tab_options', array(
	  'type' => 'none',
	  'title' => '',
	  'description' => '',
	  'weight' => 0,
	  'name' => 'navigation',
	));
	$views[$view->name] = $view;
	return $views;
}
