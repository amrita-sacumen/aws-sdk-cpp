﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/glue/model/TagResourceRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Glue::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

TagResourceRequest::TagResourceRequest() : 
    m_resourceArnHasBeenSet(false),
    m_tagsToAddHasBeenSet(false)
{
}

Aws::String TagResourceRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_resourceArnHasBeenSet)
  {
   payload.WithString("ResourceArn", m_resourceArn);

  }

  if(m_tagsToAddHasBeenSet)
  {
   JsonValue tagsToAddJsonMap;
   for(auto& tagsToAddItem : m_tagsToAdd)
   {
     tagsToAddJsonMap.WithString(tagsToAddItem.first, tagsToAddItem.second);
   }
   payload.WithObject("TagsToAdd", std::move(tagsToAddJsonMap));

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection TagResourceRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSGlue.TagResource"));
  return headers;

}




