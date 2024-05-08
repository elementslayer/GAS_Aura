// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for(const FAuraInputAction& Action : AbilityInputActions)
	{

		if(Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}

		/* My solution, forgot to check for null
		if (Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}*/
	}

	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find ability Input action for InputTag [%s], on InputConfig  "), *InputTag.ToString());
	}

	return nullptr;
}
