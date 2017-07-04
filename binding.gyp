{
  "targets": [
    {
      "target_name": "node-helib",
	  "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "dependencies": [
        "dep/HElib.gyp:helib"
      ],
      "sources": [
        "src/main.cpp"
      ]
    }
  ]
}