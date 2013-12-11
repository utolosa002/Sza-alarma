<div class="navbar navbar-inverse navbar-fixed-top">
	<div class="navbar-inner">
		<a class="brand" href="./index.php">Alarma!</a>
		<form class="navbar-form pull-right" id="identifikatu" action="identifikatu.php" method='post'> 	
			<fieldset>
				<input type="text" class="span2" id="izena" name="izena" size="15" value="izena" onfocus="kendubalioa(this)" onblur="emanbalioa(this,'izena')"/>
				<input type="password" class="span2" id="pasahitza" name="pasahitza" value="pasahitza" size="15" onfocus="kendubalioa(this)" onblur="emanbalioa(this,'pasahitza')" />
				<button type="submit" class="btn">Sartu!</button>
 			</fieldset>
		</form>
	</div>
</div>
