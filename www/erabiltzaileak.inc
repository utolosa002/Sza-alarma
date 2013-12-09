<?php include 'access.inc' ?>  
<?php
/*
Uneko erabiltzailea ez den beste erabiltzaileak itzultzen ditu array batean.
Ez du parametrorik jasotzen.
*/
	function BesteErabiltzaileak(){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="SELECT `e`.`iderab`,`e`.`nicka`, `e`.`emaila` FROM `Erabiltzaile` AS `e` WHERE NOT(`e`.`emaila` =\"$erabil\" OR `e`.`nicka` =\"$erabil\")";
 		$Erabiltzaileak=mysql_query($query,$link);
 		if(mysql_num_rows($Erabiltzaileak)==false){
			return false;
		}else{
			while($Erabiltzailea= mysql_fetch_assoc($Erabiltzaileak)){
 				$ErabiltzaileaArray[] = $Erabiltzailea;
			}
		}
		return $ErabiltzaileaArray;
	}	
	
/*
Erabiltzailearen ida parametro gisa pasatzen zaio eta 
bere alarmen ideak edo alarmarik ez duela itzultzen du.
*/
	function lortuErabAlarmak($erabil){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="SELECT `ea`.`idalarma` FROM `Erabiltzaile` AS `e` INNER JOIN `Erab_alarma` AS `ea` INNER JOIN `Alarma` AS `a` WHERE `ea`.`iderab` = `e`.`iderab` AND `a`.`idalarma` = `ea`.`idalarma` AND  `e`.`iderab` =\"$erabil\"";
 		$Alarmak=mysql_query($query,$link);
 		if(mysql_num_rows($Alarmak)==false){
			return "alarmarik ez du";
		}else{
			while($alarma= mysql_fetch_row($Alarmak)){
				foreach ($alarma as $balioa){
   					if (!$AlarmaS){
      						$AlarmaS = $balioa;
   					}else{
						$AlarmaS .= ',' . $balioa;
   					}
				}
			}
			return $AlarmaS;
		}
	}
?>
<div class="entry">
	<h2>Erabiltzaile guztiak</h2>
	<form id="zureAlarmak" action="erabiltzailea_aldatu.php" method="post">
		<fieldset>
			<table class="table table-stripedtable-condensed">
				<tr>
					<td><h3> Ida </h3></td>
					<td><h3> Nicka </h3></td>	
					<td><h3> Emaila </h3></td>
					<td><h3> Bere Alarmak </h3></td>
				</tr>
				<?php
				$Erabiltzaileak=besteErabiltzaileak();
					if($Erabiltzaileak==false){	
						echo "<tr class=\"error\">\n<td>ez dago beste erabiltzailerik</td>\n<td></td>\n<td></td>\n<td></td>\n</tr>\n";
					}else{
						$i=0;
						$j=0;
						foreach ($Erabiltzaileak as $Erabiltzaile){
							$lerroa="";
							$k=0;
							$j=0;
							foreach ($Erabiltzaile as $EDatuak) {	
								$k++;
								if($k % 3===0){
									$lerroa="<tr class=\"info\">\n".$lerroa."<td><input type=\"text\" id=\"erab$j$k\" name=\"erab$j$k\" readonly=\"readonly\" value= \"$EDatuak\" /></td>\n<td><input type=\"text\" id=\"erab".$j."4\" name=\"erab".$j."4\" readonly=\"readonly\" value= \"$AlarmaS\" /></td>\n";
								}else{
									if(($k+2) % 3===0){
										$j=$EDatuak;
										$AlarmaS="";
										$AlarmaS=lortuErabAlarmak($EDatuak);	
										$lerroa=$lerroa."<td><input type=\"text\" id=\"erab$j$k\" name=\"erab$j$k\" readonly=\"readonly\" value= \"$EDatuak\" /></td>\n";						
									}else{
										$lerroa=$lerroa."<td><input type=\"text\" id=\"erab$j$k\" name=\"erab$j$k\" readonly=\"readonly\" value= \"$EDatuak\" /></td>\n";
									}
								}												
							}		
							echo $lerroa."</tr>\n";
						}
					}
				?>
			</table>
		</fieldset>
	</form>
 </div>
