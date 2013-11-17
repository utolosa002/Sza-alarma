<?php
	if(count(get_included_files()) ==1) header("Location: ./index.php"); 
		$datuBasea="Alarma";

	$link=mysql_connect("localhost","root","root");

	if(!$link){
		echo "<h2 align='center'>ERROREA: ezin da zerbitzariarekin konektatu!</h2>";
		exit; 
	} 
?>

