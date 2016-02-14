add_executable(app
	main.cc
	pluginwindow.cc pluginwindow.hh pluginwindow.ui
	mainwindow.cc mainwindow.hh mainwindow.ui
	applicationtools.hh applicationtools.cc
	citieswindow.cc citieswindow.hh citieswindow.ui
	cities_table_model.cc cities_table_model.hh
	cities_list_model.cc cities_list_model.hh
)

target_link_libraries(app

	plugin_manager

	Qt5::Widgets
)

set_target_properties(app PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
