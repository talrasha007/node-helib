{
  "targets": [
    {
      "target_name": "node-helib",
	  "include_dirs" : [
        "<!(node -e \"require('nan')\")",
        "dep/HElib/src"
      ],
      "dependencies": [
        "dep/HElib.gyp:helib"
      ],
      "sources": [
        "src/main.cpp",
        "src/CtxtWrap.cpp",
        "src/EncryptedArrayWrap.cpp",
        "src/FHEContextWrap.cpp",
        "src/FHESecKeyWrap.cpp"
      ],
      "conditions": [
        [
          "OS != 'win'", {
            "libraries": [
              "-lntl"
            ],
            "cflags_cc": [
              "-frtti",
              "-fexceptions",
              "-Wno-ignored-qualifiers",
              "-Wno-sign-compare"
            ]
          }
        ]
      ]
    }
  ]
}