#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <vector>

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"  
};

//指定是否需要使用校验层
#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif // DEBUG


class  HelloTriangleApplication
{
public:

private:
	GLFWwindow* window;
	unsigned int WINDOW_WIDTH = 800;
	unsigned int WINDOW_HEIGHT = 600;

	//Vulkan实例，填createinfo的目的就是为了创建Vulkan实例
	VkInstance instance;
	//需要一个VkDebugUtilsMessengerEXT对象存储回调函数的信息，帮助校验层检测
	VkDebugUtilsMessengerEXT callback;
	unsigned int extensionCount = 0;
public:
	 HelloTriangleApplication();
	~ HelloTriangleApplication();

	void run();

private:
	void initWindow();

	void mainLoop();

	void cleanUp();

	//vulkan related
	void initVulkan();

	void createInstance();

	//校验层
	//检查是否可以使用校验层
	bool checkValidationLayerSupport();
	//根据是否使用校验层，返回需要的扩展列表
	std::vector<const char*> getRequiredExtensions();
	//注册添加回调函数
	void setupDebugCallback();
	//定义接受调试信息的静态回调函数
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
		std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

		return VK_FALSE;
	}
};

