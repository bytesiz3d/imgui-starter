#include <imgui-window/Window.h>
#include <imgui.h>
#include <imgui_internal.h>

int
main(int argc, char const *argv[])
{
	if (im_window::window_init() != 0)
		return 1;

	im_window::window_run([] {
		auto dockspace_id = ImGui::DockSpaceOverViewport(nullptr, ImGuiDockNodeFlags_PassthruCentralNode);

		if (static bool first_dock = true; first_dock)
		{
			first_dock = false;
			ImGui::DockBuilderRemoveNodeChildNodes(dockspace_id);
			ImGui::DockBuilderDockWindow("Dear ImGui Demo", dockspace_id);
		}

		ImGui::ShowDemoWindow();
	});

	im_window::window_dispose();

	return 0;
}