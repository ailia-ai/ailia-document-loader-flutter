#include "include/ailia_document_loader/ailia_document_loader_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "ailia_document_loader_plugin.h"

void AiliaDocumentLoaderPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  ailia_document_loader::AiliaDocumentLoaderPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
