function balioztatu(f)
{
	var izena= f.Eizena.value;
	var emaila =f.EEmaila.value;
	var pasahitza= f.Epasahitza.value;
	if(izena==""|| emaila==""||pasahitza==""||izena==" "|| emaila==" "||pasahitza==" "){
		alert("Eremuren bat hutsa da");
		return false;
	}else{
		return emailaDa(emaila);
	}
}

function kendubalioa(f)
{
	if( f.value=="izena" || f.value=="pasahitza" || f.value=="emaila" || f.value=="Erabiltzailea" || f.value=="Alarma izena" || f.value=="Sentsore izena" ){
		f.value="";
	}
}
function emanbalioa(f,str)
{
	if(f.value==""){
		f.value=str;
	}
}

function emailaDa(str)
{
	if(str.split("@").length != 2){
		alert('Ziurtatu "@" karakterea behin, eta behin bakarrik, agertzen dela.!');		
		return false;
	}
	if(str.indexOf("@") == 0){
		alert('Ziurtatu "@" karakterea ez dela lehena.');	
		return false;
	}
	if(str.lastIndexOf(".") < str.lastIndexOf("@")){
		alert(' Ziurtatu "@" karakterearen ondoren "." karaktereren bat badagoela.');	
		return false;
	}
	if(str.lastIndexOf("@")+3 > str.lastIndexOf(".")){
		alert('Ziurtatu "@"ren atzetik gutxienez beste 2 karaktere daudela.');	
		return false;
	}	
	if(str.lastIndexOf(".") + 2 > str.length - 1){
		alert('Ziurtatu azkeneko puntuaren atzetik gutxienez beste 2 karaktere daudela.');	
		return false;
	}
	return true;
}



function gehitusents()
{
	document.getElementById("subbutton").disabled = false;
	var diva = document.getElementById("fi");
	var zenb = document.getElementsByName('sizena[]').length+1;
	var inputberria = document.createElement('input');
	inputberria.innerHTML = "<input type=\"text\" class=\"input-large\" id=\"s"+zenb+"\" name=\"sizena[]\" value=\"Sentsore izena\" onfocus=\"kendubalioa(this)\" onblur=\"emanbalioa(this,'Sentsore izena')\"/>";
	diva.appendChild(inputberria.firstChild);
}

function kendusents()
{	
	var diva = document.getElementById("fi");
	var zenb = document.getElementsByName("sizena[]").length;
	if ((zenb-1)==0){
		document.getElementById("subbutton").disabled = true;
	}
	var szenb= "s"+zenb;
  	var olddiv = document.getElementById(szenb);
	diva.removeChild(olddiv);
}
