#pragma once

#include <imgui.h>

#include <Imagination.h>

class MyLayerSubclass : public Imagination::Graphics::Layer {
public:
	MyLayerSubclass(std::string name, bool activeByDefault) : Imagination::Graphics::Layer(name), m_Active(activeByDefault) {}

	virtual void OnImGuiRender() override = 0;

	inline void ToggleActive() { m_Active = !m_Active; }
	inline void Deactivate() { m_Active = false; }

protected:
	bool m_Active;
};

class DockLayer : public Imagination::Graphics::Layer {
private:
	std::unique_ptr<MyLayerSubclass> m_HelpAboutLayer;

	float pos[3] = { 0, 0, 0 };

	std::unique_ptr<Imagination::Platform::URL> m_ManualUrl, m_ItchIoUrl;

public:
	DockLayer();

	void OnImGuiRender() override;
};

class HelpAboutLayer : public MyLayerSubclass {
private:
	std::string m_About;

public:
	HelpAboutLayer();

	void OnImGuiRender() override;
};