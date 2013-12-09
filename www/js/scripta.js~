function balioztatu(f)
{
	var izena= f.Eizena.value;
	var emaila =f.EEmaila.value;
	var pasahitza= f.Epasahitza.value;
	if(izena==""|| emaila==""||pasahitza==""||izena==" "|| emaila==" "||pasahitza==" ")
	{
		alert("zeoze hutsa da");
		return false;
	}else{
		if (emailaDa(emaila))
		{
			return true;
		}else{		
			return false;
		}
	}
}

function kendubalioa(f)
{
	if(f.value=="izena"||f.value=="pasahitza"||f.value=="emaila"||f.value=="Erabiltzailea"||f.value=="Alarma izena"){
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
	var APos = str.split('@');
  	var DotPos = str.split('.');
	var posabildua = str.indexOf('@');
	var pospuntu = str.indexOf('.');	
	var azkenpuntu = str.lastIndexOf('.');
 	var batzatia = str.substring(0,posabildua);
	var bizatia = str.substring(posabildua+1,pospuntu);
	var azkenzatia = str.substring(azkenpuntu+1,str.length);
   	
	if (2<APos.length){
		alert("emaila gaizki .. @@");
		return false;
	}else{
		if(batzatia.length<1){
			alert("emaila gaizki, @ aurretik hutsa");
			
			return false;
		}else{
			if (azkenpuntu<posabildua) {
				alert("emaila gaizki, puntua @ aurretik");
				return false;
			}else{
				if(bizatia.length<1){
					alert("emaila gaizki, @ ondoren hutsa");
					return false;
				}else{
					if(azkenzatia.length<2){
						alert("emaila gaizki, puntuaren ondoren zerbait jarri");	
						return false;
					}else{
						return true;
					}
				}
			}
		}
	}
}



function gehitusents()
{
	document.getElementById("subbutton").disabled = false;
	var diva = document.getElementById("fi");
	var zenb = document.getElementsByName('sizena[]').length+1;
	var inputberria = document.createElement('input');
	inputberria.innerHTML = "<input type=\"text\" class=\"input-large\" id=\"s"+zenb+"\" name=\"sizena[]\" placeholder=\"sentsore izena\" required=\"required\"/>";
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

function AtzeaGorri(elementua)
{
  document.getElementById(elementua).style.background = "red";
  document.getElementById(elementua).style.color = "Black";
}
function AtzeaTxuri(elementua)
{
  document.getElementById(elementua).style.background = "white";
  document.getElementById(elementua).style.color = "Black";
}
function checkAkti()
{

  document.getElementById("publikatu").disabled = false;
}
