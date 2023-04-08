#include <imgui-window/Window.h>
#include <imgui-window/Dockspace.h>

int
main(int argc, char const *argv[])
{
	if (im_window::window_init() != 0)
		return 1;

	im_window::window_run([] {
		static bool reset_dockspace = true;
		im_window::dockspace({
			{"Dear ImGui Demo", 0.33f},
			{im_window::SPLIT_HORIZONTAL, 0.5f, {
				{"Middle Top", 0.3f},
				"Middle Bottom",
			}},
			"Rightmost"
		}, &reset_dockspace);

		ImGui::ShowDemoWindow();

		if (ImGui::Begin("Middle Top"))
		{
			if (ImGui::Button("Reset dockspace"))
				reset_dockspace = true;
		}
		ImGui::End();

		if (ImGui::Begin("Middle Bottom"))
		{
			if (ImGui::Button("Reset dockspace"))
				reset_dockspace = true;
		}
		ImGui::End();

		if (ImGui::Begin("Rightmost"))
		{
			if (ImGui::Button("Reset dockspace"))
				reset_dockspace = true;
		}
		ImGui::End();
	});

	im_window::window_dispose();

	return 0;
}