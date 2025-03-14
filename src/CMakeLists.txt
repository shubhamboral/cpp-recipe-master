# UI Processing for Qt
qt_wrap_ui(UI_HEADERS mainwindow.ui)

# Create a library for UI-generated sources
add_library(UISources ${UI_HEADERS})

# Link with Qt6 Widgets
target_link_libraries(UISources PRIVATE Qt6::Widgets)
