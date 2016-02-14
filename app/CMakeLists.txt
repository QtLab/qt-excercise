add_executable(app
	main.cc
	pluginwindow.cc pluginwindow.hh pluginwindow.ui
	mainwindow.cc mainwindow.hh mainwindow.ui
	applicationtools.hh applicationtools.cc
)

target_link_libraries(app

	plugin_manager

	Qt5::Widgets
)

set_target_properties(app PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
