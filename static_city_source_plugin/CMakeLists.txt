add_library(static_city_provider_plugin SHARED
	plugin.cc plugin.hh
	staticCityProvider.cc staticCityProvider.hh
)

target_link_libraries(static_city_provider_plugin
	plugin_interfaces

	Qt5::Core
)


set_target_properties(static_city_provider_plugin PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

