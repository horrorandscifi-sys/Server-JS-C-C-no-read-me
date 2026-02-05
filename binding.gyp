{
  "targets": [{
    "target_name": "high_load_engine",
    "sources": [ "src/native/main.cpp" ],
    "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
    "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
    "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
  }]
}
