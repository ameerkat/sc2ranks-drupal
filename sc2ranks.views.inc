<?php
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
			"handler"	=> "views_handler_field",
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