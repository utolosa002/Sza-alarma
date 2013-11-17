<?php include 'access.inc' ?>  
<?php
	function BesteErabiltzaileak(){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="SELECT `e`.`iderab`,`e`.`nicka`, `e`.`emaila` FROM `erabiltzaile` AS `e` WHERE NOT(`e`.`emaila` =\"$erabil\" OR `e`.`nicka` = \"$erabil\")";
 		$Erabiltzaileak=mysql_query($query,$link);
 		if(mysql_num_rows($Erabiltzaileak)==0){
			echo "<script type='text/javascript'> alert('Hutsa Dago, Ez dago beste erabiltzailerik'); </script>";
			return false;
		}else{
			while($Erabiltzailea= mysql_fetch_assoc($Erabiltzaileak)){
 				$ErabiltzaileaArray[] = $Erabiltzailea;
			}
		}
		return $ErabiltzaileaArray;
	}	

	function lortuErabAlarmak($erabil){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="SELECT `ea`.`alarma` FROM `erabiltzaile` AS `e` INNER JOIN `erab_alarma` AS `ea` INNER JOIN `Alarma` AS `a` WHERE `ea`.`iderab` = `e`.`iderab` AND `a`.`alarmaid` = `ea`.`alarma` AND  `e`.`iderab` =\"$erabil\"";
 		$Alarmak=mysql_query($query,$link);
 		if(mysql_num_rows($Alarmak)==0){
			return "alarmarik ez du";
		}else{
			while($alarma= mysql_fetch_row($Alarmak)){
				foreach ($alarma as $balioa){
   					if (!$AlarmaS){
        					$AlarmaS = $balioa[0];
					}else{
        					$AlarmaS .= ',' . $balioa[0];
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
				$pId=$_GET['al'];
			}
			$Erabiltzaileak=besteErabiltzaileak();
			echo "<h2>$pId. alarma elkarbanatu</h2>";
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
				?>
			</table>
			<button type="submit" class="btn btn-primary btn-large" name="eBanatu" >Erabiltzailearekin elkarbanatu</button>
			</fieldset>
		</form>
 	</div>
