#ifndef FLUTTER_PLUGIN_AILIA_DOCUMENT_LOADER_PLUGIN_H_
#define FLUTTER_PLUGIN_AILIA_DOCUMENT_LOADER_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace ailia_document_loader {

class AiliaDocumentLoaderPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  AiliaDocumentLoaderPlugin();

  virtual ~AiliaDocumentLoaderPlugin();

  // Disallow copy and assign.
  AiliaDocumentLoaderPlugin(const AiliaDocumentLoaderPlugin&) = delete;
  AiliaDocumentLoaderPlugin& operator=(const AiliaDocumentLoaderPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace ailia_document_loader

#endif  // FLUTTER_PLUGIN_AILIA_DOCUMENT_LOADER_PLUGIN_H_
