#pragma once

#include "Log.h"
#include "Application.h"

#include "Core.h"

int main() {
	IMAGINATION_LOG_INFO("Hello Imagination!");

	Imagination::Application* app = Imagination::CreateApplication();

	app->Run();

	delete app;

	IMAGINATION_LOG_INFO("Goodbye, see you next time!");
}