var context;
function init(){
    //new QWebChannel(qt.webChannelTransport, function(channel){context = channel.objects.context;});
	document.getElementById("in1").value = 5000;
	
    document.getElementById("bn1").onclick=onBtnSendMsg;
	
	//alert("msgutils2.js init().");
};
function onBtnSendMsg(){
    var cmd = document.getElementById("in1").value;sendMessage(cmd);
};
function sendMessage(msg){
    //context.onMsg(1, msg);
	alert(msg+msg);
	var r = mainpage(msg);
	if (r===0){
		document.getElementById("in1").value = r;
	}
};
function recvMessage(msg){
    var obj = document.getElementById("in1");
    obj.value=msg;
    return "index.html--recvMessage";
};
init();
