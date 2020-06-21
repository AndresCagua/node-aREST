$(document).ready(function(){
	const mainUrl = "/serial";
	var lcdUrl = "/lcd?params=";
	const led = 13;
	
	const onOffLedUrl = "/digital/" + led + "/";
	getRequest(mainUrl + `/mode/${led}/o`);

	$('#on').click(function(){
		getRequest(mainUrl+onOffLedUrl+'1');
	});

	$('#off').click(function(){
		getRequest(mainUrl+onOffLedUrl+'0');
	});

	$('#enviar').click(function(){
		getRequest(mainUrl+lcdUrl+$("#texto").val());
	});
});

function getRequest(url)
{
	$.get(url, function(response){
		console.log(response);
		$("#console").text(JSON.stringify(response, null, 2));
	});
}
