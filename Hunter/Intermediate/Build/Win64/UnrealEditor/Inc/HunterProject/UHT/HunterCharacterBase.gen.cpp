// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HunterProject/Public/Character/HunterCharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHunterCharacterBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	HUNTERPROJECT_API UClass* Z_Construct_UClass_AHunterCharacterBase();
	HUNTERPROJECT_API UClass* Z_Construct_UClass_AHunterCharacterBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HunterProject();
// End Cross Module References
	void AHunterCharacterBase::StaticRegisterNativesAHunterCharacterBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHunterCharacterBase);
	UClass* Z_Construct_UClass_AHunterCharacterBase_NoRegister()
	{
		return AHunterCharacterBase::StaticClass();
	}
	struct Z_Construct_UClass_AHunterCharacterBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHunterCharacterBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_HunterProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHunterCharacterBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHunterCharacterBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/HunterCharacterBase.h" },
		{ "ModuleRelativePath", "Public/Character/HunterCharacterBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHunterCharacterBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHunterCharacterBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHunterCharacterBase_Statics::ClassParams = {
		&AHunterCharacterBase::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHunterCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AHunterCharacterBase_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AHunterCharacterBase()
	{
		if (!Z_Registration_Info_UClass_AHunterCharacterBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHunterCharacterBase.OuterSingleton, Z_Construct_UClass_AHunterCharacterBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHunterCharacterBase.OuterSingleton;
	}
	template<> HUNTERPROJECT_API UClass* StaticClass<AHunterCharacterBase>()
	{
		return AHunterCharacterBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHunterCharacterBase);
	AHunterCharacterBase::~AHunterCharacterBase() {}
	struct Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterCharacterBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterCharacterBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHunterCharacterBase, AHunterCharacterBase::StaticClass, TEXT("AHunterCharacterBase"), &Z_Registration_Info_UClass_AHunterCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHunterCharacterBase), 2365263307U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterCharacterBase_h_1410673579(TEXT("/Script/HunterProject"),
		Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dev_HunterProject_Hunter_Source_HunterProject_Public_Character_HunterCharacterBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
