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
					<span id="sc2ranks-character-code" style="color: #AAAAAA;">
					#<?php print($record_data->character_code); ?>
					</span>
				</td>
				<td><?php print($record_data->fav_race); ?></td>
				<td><img src="<?php print $league_image_url ?>" alt="<?php print($record_data->league); ?>" style="width: 25px;"/></td>
				<td><?php print($record_data->points); ?></td>
				<td><?php print($record_data->division); ?></td>
				<td><?php print($record_data->wins); ?></td>
				<td><?php print($record_data->losses); ?></td>
				<td><?php print($ratio); ?>%</td>
			</tr>
		</tbody>
	</table>
</div>
<?php else: ?>
Data Not Available
<?php endif; ?>
