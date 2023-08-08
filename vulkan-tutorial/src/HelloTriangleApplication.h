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

//ָ���Ƿ���Ҫʹ��У���
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

	//Vulkanʵ������createinfo��Ŀ�ľ���Ϊ�˴���Vulkanʵ��
	VkInstance instance;
	//��Ҫһ��VkDebugUtilsMessengerEXT����洢�ص���������Ϣ������У�����
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

	//У���
	//����Ƿ����ʹ��У���
	bool checkValidationLayerSupport();
	//�����Ƿ�ʹ��У��㣬������Ҫ����չ�б�
	std::vector<const char*> getRequiredExtensions();
	//ע����ӻص�����
	void setupDebugCallback();
	//������ܵ�����Ϣ�ľ�̬�ص�����
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
		std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

		return VK_FALSE;
	}
};

