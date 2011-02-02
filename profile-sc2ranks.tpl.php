<?php if($record_data): ?>
<div id="sc2ranks-wrapper" class="sc2ranks">
	<table id="sc2ranks-table" class="sc2ranks">
		<thead>
			<tr>
				<th>Character</th>
				<th>Race</th>
				<th>League</th>
				<th>Points</th>
				<th>Division</th>
				<th>Wins</th>
				<th>Losses</th>
				<th>Ratio</th>
			</tr>
		</thead>
		<tbody>
			<tr>
				<td>
					<span id="sc2ranks-character-name">
					<?php print($record_data->character_name); ?>
					</span>
					<?php if ($show_code || user_access('access character code')): ?>
						<span id="sc2ranks-character-code" style="color: #AAAAAA;">
						#<?php print($record_data->character_code); ?>
						</span>
					<?php endif; ?>
				</td>
				<td><img src="<?php print $race_image_url ?>" alt="<?php print($record_data->fav_race); ?>" /></td>
				<td><img src="<?php print $league_image_url ?>" alt="<?php print($record_data->league); ?>" style="width: 25px;"/></td>
				<td><?php print($record_data->points); ?></td>
				<td><?php print($record_data->division); ?></td>
				<td><?php print($record_data->wins); ?></td>
				<td><?php print($record_data->losses); ?></td>
				<td><?php print(number_format($ratio, 2)); ?>%</td>
			</tr>
		</tbody>
	</table>
	<div id="sc2ranks-link" style="font-size: 8pt; text-align: right; margin-right: 5px;">
	<a href="<?php print($sc2ranks_profile_url); ?>">
		<img src="<?php print($sc2ranks_icon_url); ?>" />
		<span style="position: relative; top: -4px;"> sc2ranks</span></a>
	<a href="<?php print($bnet_profile_url); ?>">
		<img src="<?php print($bnet_icon_url); ?>" style="margin-left: 5px;">
		<span style="position: relative; top: -4px;"> bnet</span></a>
	</div>
</div>
<?php else: ?>
Data Not Available
<?php endif; ?>
