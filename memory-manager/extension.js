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