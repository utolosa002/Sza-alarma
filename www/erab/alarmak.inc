<?php
/*
Funtzio honek uneko erabiltzailearen alarmak itzultzen ditu (false hutsa bada).
*/
	function lortuZureAlarmak(){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="SELECT `ea`.`idalarma`, `a`.`aizena`, `a`.`aegoera` FROM `Erabiltzaile` AS `e` INNER JOIN `Erab_alarma` AS `ea` INNER JOIN `Alarma` AS `a` WHERE `ea`.`iderab` = `e`.`iderab` AND `a`.`idalarma` = `ea`.`idalarma` AND `e`.`nicka` = \"$erabil\"";
 		$Alarmak=mysql_query($query,$link);
 		if(mysql_num_rows($Alarmak)==0){
			return false;
		}else{
			while($alarma= mysql_fetch_assoc($Alarmak)){
				$AlarmaArray[] = $alarma;
			}
		}
		return $AlarmaArray;
	}
?>
<div class="entry">
	<h2>Alarma guztiak</h2>
	<?php 
		$Alarmak=lortuZureAlarmak();
		if($Alarmak==false) {
			echo "<table class=\"table table-stripedtable-condensed\"><tr><td><h3>Alarmarik ez daukazu </h3></td></tr></table>";
		}else{
	?>
	<form id="zureAlarmak" action="alarmaAldatu.php" method="post">
		<fieldset>
			
			<table class="table table-stripedtable-condensed">
				<tr>
					<td><h3> Zenb </h3></td>
					<td><h3> Izena </h3></td>	
					<td><h3> Egoera </h3></td>
					<td><h3> Hautatu </h3></td>
				</tr>
				<?php 
					$j=0;
					foreach ($Alarmak as $Alarma){
						$lerroa="";
						$j++;
						$k=0;
						foreach ($Alarma as $AlDatuak) {
							$k++;
							if($k % 3===0){
								if($AlDatuak==="0"){
									$lerroa="<tr class=\"success\">\n".$lerroa."<td><input type=\"text\" id=\"alarma$j$k\" name=\"alarma$j$k\" readonly=\"readonly\" value= \"Ixilik\" /></td>\n";
								}else{
									$lerroa="<tr class=\"error\">\n".$lerroa."<td><input type=\"text\" id=\"alarma$j$k\" name=\"alarma$j$k\" readonly=\"readonly\" value= \"JOTZEN!\" /></td>\n";
								}
							}else{
								if(($k+2) % 3===0){
									$j=$AlDatuak;
	$lerroa=$lerroa."<td><input class=\"uneditable-input input-mini\" type=\"text\" id=\"alarma$j$k\" name=\"alarma$j$k\" readonly=\"readonly\" value= \"$AlDatuak\" /></td>\n";
								}else{
								$lerroa=$lerroa."<td><input class=\"uneditable-input\" type=\"text\" id=\"alarma$j$k\" name=\"alarma$j$k\" readonly=\"readonly\" value= \"$AlDatuak\" /></td>\n";
								}
							}										
						}		
						echo $lerroa."<td><input type=\"radio\" name=\"hautatu\" value=\"$j\"/></td></tr>\n";
					}
				?>
			</table>
			<button type="submit" class="btn btn-primary btn-large" id="aAldatu" name="aAldatu" >Alarmaren egoera aldatu</button>
			<button type="submit" class="btn btn-primary btn-large" name="aIkusi" >Alarmaren sentsoreak ikusi</button>
			<button type="submit" class="btn btn-primary btn-large" name="aBanatu" >Alarma elkarbanatu</button>
			<button type="submit" class="btn btn-primary btn-large" name="sGehitu" >Sentsorea gehitu</button>
			<button type="submit" class="btn btn-primary btn-large" name="aEzabatu">Alarma ezabatu</button>
		</fieldset>
	</form>
	<?php
	}
	?>
</div>
