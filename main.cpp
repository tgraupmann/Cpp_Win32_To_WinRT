// Ref: https://docs.microsoft.com/en-us/cpp/cppcx/wrl/how-to-activate-and-use-a-windows-runtime-component-using-wrl?redirectedfrom=MSDN&view=msvc-170
//
// Win32_Cpp_WinRT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.Foundation.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <stdio.h>

using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

#pragma comment(lib, "windowsapp")

int main()
{
	// Initialize the Windows Runtime.
	RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
	if (FAILED(initialize))
	{
		fprintf(stderr, "Failed to initialize WinRT! Line: %d Result: %ld\n", __LINE__, (HRESULT)initialize);
		return -1;
	}

	printf("WinRT initialzed!\n");

	// Get the activation factory for the IUriRuntimeClass interface.
	ComPtr<IUriRuntimeClassFactory> uriFactory;
	HRESULT hr = GetActivationFactory(HStringReference(RuntimeClass_Windows_Foundation_Uri).Get(), &uriFactory);
	if (FAILED(hr))
	{
		fprintf(stderr, "Failed to get WinRT class! Line: %d Result: %ld\n", __LINE__, hr);
		return -1;
	}

	printf("WinRT class found!\n");

	
	return 0;
}
