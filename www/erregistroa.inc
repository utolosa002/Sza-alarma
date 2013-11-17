<h4 class="kursiba">Oraindik ez duzula izena eman?</h4>
<form id="erregistratu" class="form-signin" enctype="multipart/form-data" onsubmit="return balioztatu(this)" action="erregistratu.php" method='post'>
	<fieldset>
		<h3 class="form-signin-heading">Erregistratu zaitez</h3>
		<label id="izenerreg">Sartu erab. izena</label>
		<input type="text" class="input-large" id="Eizena" name="Eizena" value="Erabiltzailea" onfocus="kendubalioa(this)" onblur="emanbalioa(this,'Erabiltzailea')"/>
		<label id="emailerreg">Sartu zure emaila</label>
		<input type="text" class="input-large" id="EEmaila" name="EEmaila" value="emaila" onfocus="kendubalioa(this)" onblur="emanbalioa(this,'emaila')"/>
		<label id="pasaerreg">Sartu pasahitza</label>
		<input type="password" class="input-large" id="Epasahitza" name="Epasahitza" size="15" value="pasahitza" onfocus="kendubalioa(this)" onblur="emanbalioa(this,'pasahitza')"/>
		<button type="submit" class="btn btn-large btn-primary">Izena eman</button>
		<button type="reset" class="btn btn-large btn-primary"> Garbitu</button>
	</fieldset>
</form>
