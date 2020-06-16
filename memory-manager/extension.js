// REALIZADO CON API. Estructura de API, modificaciones y adaptaciones por Esteban Morales.
// Contenedor de extension. 

//Declaracion de constantes necesarias
const vscode = require('vscode');
const net = require('net')

// Metodo llamado una vez activa la extension.

/**
 * @param {vscode.ExtensionContext} context
 */
function activate(context) {

	// Realice diagnostico con "console.log" y errores con "console.error", con la extension ACTIVA!
	console.log('Congratulations, your extension "memory-manager" is now active!');

	// Comando defino en package.json.
	// Implementacion de comando para mostar mensaje de activacion.
	let disposable = vscode.commands.registerCommand(
		'memory-manager.garbagecollector',
		 function () {
		//Mensaje en pantalla:
		vscode.window.showInformationMessage('Interfaz visual from memory-manager!');
	
	}
	);

	//Variable de alamacen de comando y fucion de inicio
	let init = vscode.commands.registerCommand('memory-manager.start',
	function(){

		// Mensaje en pantalla.
		vscode.window.showInformationMessage('La extension esta activada correctamente');

		// creacion de 'webview panel' (estructa recuperada del API oficial)
		const panel = vscode.window.createWebviewPanel(
			'HS',
			'Memory Manager',
			vscode.ViewColumn.One,
			{
				enableScripts: true
			}
		);

		// Configuracion del "webview panel" con HTML
		panel.webview.html = getWebviewContent();

		// Mensaje del webview
		var registered = false;  
      	panel.webview.onDidReceiveMessage(
        	message => {
          		switch (message.command) {
            	case 'connect':
					if (!registered){
						clientSrv.write("p "+message.text);
						return;
					}else{
						vscode.window.showInformationMessage("Conectado correctamente");
					  	return;
					}
				case 'empty':
					vscode.window.showErrorMessage("Contraseña incorrecta");
					return;

				case 'empty2':
					vscode.window.showErrorMessage("Debe escribir un ID");
					return;
					  
				/*case 'save':
					clientLib.write('2');
					return;
*/
				case 'asked':
					vscode.window.showInformationMessage("VSPtr correspondiente al ID="+message.text);
					clientSrv.write("ID"+message.text);
					return;
				}
        	},
        	undefined,
        	context.subscriptions
      	);

		// Creacion del HTML necesaio para el  webView
		function getWebviewContent(labels,data,dirs) {
			return `<!DOCTYPE html>
			<html lang="en">
			<head>
			<meta charset="UTF-8">
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<title>Memory Manager</title>
			<script> </script>
			</head>
			<body>
            <canvas id="myChart" width="350" height="270"></canvas>
			<script>
				const vscode = acquireVsCodeApi();
                var ctx = document.getElementById('myChart').getContext('2d');
                var myChart = new Chart(ctx, {
                    type: 'bar',
                    data: {
                        labels: [${labels}],
                        datasets: [${data}]
                    },
                    options: {
                        scales: {
                            yAxes: [{
                                ticks: {
                                    beginAtZero: true
                                }
                            }]
                        }
					}
					
					
				});
				</script>
				<p>Direcciones de memoria por dato:<br><br>${dirs}</p>
				<p></p>
                <button style="background-color:#007bcd; border-color:#007bcd; color:white", onclick="document.getElementById('id01').style.display='block'" style="width:auto;">Connect to server</button>
	
                <div id="id01" class="modal" style="display: none">
					<div class="container">
                    <p></p>
                    <label><b>Password</b></label>
                    <input type="password" placeholder="Enter Password" id="psw">
                    <button id= "passwordLogin", style="background-color:#007bcd; border-color:#007bcd; color:white">Login</button>
                    </div>
                    <div class="container">
                    <button type="button", style="background-color:#007bcd; border-color:#007bcd; color:white" onclick="document.getElementById('id01').style.display='none'" class="cancelbtn">Cancel</button>
					</div>	
				</div>
				
				<p>Funciones de servidor:<br></p>
				<button id="save" disabled>Save pointers</button>
				<button id="ask", onclick="document.getElementById('id02').style.display='block'" disabled>Ask for VSPtr data</button>
				<div id="id02" class="modal" style="display: none">
					<div class="container">
					<br>
					<label ><b>VSPtr ID</b></label>
					<input placeholder="Enter VSPtr ID" id="id">
					<button id= "idSend", style="background-color:#007bcd; border-color:#007bcd; color:white">Send</button>
					</div>
					<div class="container">
					<button type="button", style="background-color:#007bcd; border-color:#007bcd; color:white" onclick="document.getElementById('id02').style.display='none'" class="cancelbtn">Cancel</button>
					</div>
				</div>
				
                
				<script>
				
  					document.getElementById("passwordLogin").addEventListener('click',function(){
						var pws = document.getElementById("psw").value;
						if (pws != ''){
							var modal = document.getElementById('id01');
							modal.style.display = "none";
							vscode.postMessage({
								command : 'connect',
								text : ""+pws+""
							})
							document.getElementById("passwordLogin").clear;
						}else{
							vscode.postMessage({
								command : 'empty'
							})
						}
					});
					document.getElementById("save").addEventListener('click',function(){
						vscode.postMessage({
							command : 'save'
						})
					});
					document.getElementById("idSend").addEventListener('click',function(){
						var ask = document.getElementById("id").value;
						if (ask != ''){
							var modal = document.getElementById('id02');
							modal.style.display = "none";
							vscode.postMessage({
								command : 'asked',
								text : ""+ask+""
							})
						}else{
							vscode.postMessage({
								command : 'empty2'
							})
						}
					});
					window.addEventListener('message', event => {
						const message = event.data; // The JSON data our extension sent
			
						switch (message.command) {
							case 'connected':
								var save = document.getElementById("save");
								save.style.background ='#007bcd';
								save.style.borderColor = '#007bcd';
								save.style.color = 'white';
								save.disabled = false;
								var ask = document.getElementById("ask");
								ask.style.background ='#007bcd';
								ask.style.borderColor = '#007bcd';
								ask.style.color = 'white';
								ask.disabled = false;
								
								break;
						}
					});
					
                </script>
			</body>
			</html>`;
		}

		
	

	context.subscriptions.push(disposable);
	context.subscriptions.push(init);

}
exports.activate = activate;

// this method is called when your extension is deactivated
function deactivate() {}

module.exports = {
	activate,
	deactivate
}