<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
        "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<?php include 'goiburua.inc' ?>
		<?php include_once 'access.inc' ?>
	</head>
	<body>
		<?php include 'menuBarru.inc' ?>
		<div class="container-fluid">
			<div class="row-fluid">
				<div class="span9">
					<div class="hero-unit">
					<?php 
						if(isset($_GET['alarmak'])){
							include('alarmak.inc');
						}else if(isset($_GET['sentsoreak'])){
							include('sentsoreak.inc'); 
						}else if(isset($_GET['zerda'])){
							include('zerda.inc');
						}else if(isset($_GET['erab'])){
							include('erabiltzaileak.inc');
						}else if(isset($_GET['elkarbanatu'])){
							include('elkarbanatu.inc');
						}else if(isset($_GET['sen_gehitu'])){
							include('sgehitu.inc');
						}else if(isset($_GET['berria'])){
							include('berria.inc');
						}else if(isset($_GET['sen_berria'])){
							include('sBerria.php');
						}else if(isset($_GET['alarma_berria'])){
							include('aBerria.php');
						}else if(isset($_GET['irten'])){
							include('irten.inc');
						}else{
							include('hasi.inc');}
					?>      
      					</div><!--/hero-unit-->
				</div><!--/.span9-->
			</div><!--/row-fluid-->
		</div><!--/.container-fluid--> 
		<?php include 'oina.inc' ?>
	</body>
</html>
