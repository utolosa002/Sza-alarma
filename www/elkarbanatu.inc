<?php include 'access.inc' ?>  
<?php
/*
Funtzio honek uneko erabiltzailea ez diren erabiltzaileak itzultzen ditu (false hutsa bada).
Uneko erabiltzailea SESSION bidez jasotzen du.
*/
	function BesteErabiltzaileak(){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="SELECT `e`.`iderab`,`e`.`nicka`, `e`.`emaila` FROM `Erabiltzaile` AS `e` WHERE NOT(`e`.`emaila` =\"$erabil\" OR `e`.`nicka` = \"$erabil\")";
 		$Erabiltzaileak=mysql_query($query,$link);
 		if(mysql_num_rows($Erabiltzaileak)==0){
			return false;
		}else{
			while($Erabiltzailea= mysql_fetch_assoc($Erabiltzaileak)){
 				$ErabiltzaileaArray[] = $Erabiltzailea;
			}
		}
		return $ErabiltzaileaArray;
	}	

/*
Funtzio honek erabiltzailearen alarmak itzultzen ditu string batean kateaturik. 
alarmarik ez badu 'alarmarik ez du' stringa itzultzen du.
Erabiltzailearen ida jaso eta bere alarmak lortzen ditu.
*/
	function lortuErabAlarmak($erabil){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="SELECT `ea`.`idalarma` FROM `Erabiltzaile` AS `e` INNER JOIN `Erab_alarma` AS `ea` INNER JOIN `Alarma` AS `a` WHERE `ea`.`iderab` = `e`.`iderab` AND `a`.`idalarma` = `ea`.`idalarma` AND  `e`.`iderab` =\"$erabil\"";
 		$Alarmak=mysql_query($query,$link);
 		if(mysql_num_rows($Alarmak)==0){
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
		
		<?php 
			if(isset($_GET['al'])) {
				$paId=$_GET['al'];
			}
			$Erabiltzaileak=besteErabiltzaileak();
			if($Erabiltzaileak==false){
				echo "<h2>Erabiltzaile bakarra zara, ezin duzu elkarbanatu</h2>";
			}else{
				echo "<h2>$paId. alarma elkarbanatu</h2>";
			}
		?>
		
		<form id="zureAlarmak" action="erabiltzailea_aldatu.php" method="post">
			<fieldset>
			
			<table class="table table-stripedtable-condensed">
				<tr>
					<td><h3> Ida </h3></td>
					<td><h3> Nicka </h3></td>	
					<td><h3> Emaila </h3></td>
					<td><h3> Bere Alarmak </h3></td>
					<td><h3> hautatu </h3></td>
				</tr>
		<?php 
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
							echo $lerroa."<td><input type=\"radio\" name=\"hautatu\" value=\"$j\"/></td></tr>\n";
						}
				echo "<input type=\"hidden\" name=\"idalarma\" value=\"$paId\"/>";
				?>
			</table>
			<button type="submit" class="btn btn-primary btn-large" name="eBanatu">Erabiltzailearekin elkarbanatu</button>
			</fieldset>
		</form>
 	</div>
