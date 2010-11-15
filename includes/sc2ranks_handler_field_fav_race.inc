<?php
/**
 * Custom views handler for race (provides images)
 */
class sc2ranks_handler_field_fav_race extends views_handler_field {
	function render($values){
		return "<img src=\"".base_path().drupal_get_path('module', 'sc2ranks').
		"/images/icon-race-".$values->cache_sc2ranks_fav_race.".jpg\" alt=\"".
		$values->cache_sc2ranks_fav_race."\" />";
	}
}