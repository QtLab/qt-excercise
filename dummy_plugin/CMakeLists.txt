add_library(dummy_plugin SHARED
	dummy_plugin.hh
	dummy_plugin.cc
)

target_link_libraries(dummy_plugin
	plugin_interfaces

	Qt5::Core
)


set_target_properties(dummy_plugin PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
