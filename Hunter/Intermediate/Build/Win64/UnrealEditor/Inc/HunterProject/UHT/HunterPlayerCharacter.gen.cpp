// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HunterProject/Public/Character/HunterPlayerCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHunterPlayerCharacter() {}
// Cross Module References
	HUNTERPROJECT_API UClass* Z_Construct_UClass_AHunterCharacterBase();
	HUNTERPROJECT_API UClass* Z_Construct_UClass_AHunterPlayerCharacter();
	HUNTERPROJECT_API UClass* Z_Construct_UClass_AHunterPlayerCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HunterProject();
// End Cross Module References
	void AHunterPlayerCharacter::StaticRegisterNativesAHunterPlayerCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHunterPlayerCharacter);
	UClass* Z_Construct_UClass_AHunterPlayerCharacter_NoRegister()
	{
		return AHunterPlayerCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AHunterPlayerCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHunterPlayerCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHunterCharacterBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HunterProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHunterPlayerCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHunterPlayerCharacter_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/HunterPlayerCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/HunterPlayerCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHunterPlayerCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHunterPlayerCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHunterPlayerCharacter_Statics::ClassParams = {
		&AHunterPlayerCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHunterPlayerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AHunterPlayerCharacter_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AHunterPlayerCharacter()
	{
		if (!Z_Registration_Info_UClass_AHunterPlayerCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHunterPlayerCharacter.OuterSingleton, Z_Construct_UClass_AHunterPlayerCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHunterPlayerCharacter.OuterSingleton;
	}
	template<> HUNTERPROJECT_API UClass* StaticClass<AHunterPlayerCharacter>()
	{
		return AHunterPlayerCharacter::StaticClass();
	}
	AHunterPlayerCharacter::AHunterPlayerCharacter() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHunterPlayerCharacter);
	AHunterPlayerCharacter::~AHunterPlayerCharacter() {}
	struct Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterPlayerCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterPlayerCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHunterPlayerCharacter, AHunterPlayerCharacter::StaticClass, TEXT("AHunterPlayerCharacter"), &Z_Registration_Info_UClass_AHunterPlayerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHunterPlayerCharacter), 2128227450U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterPlayerCharacter_h_2565828904(TEXT("/Script/HunterProject"),
		Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterPlayerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterPlayerCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
