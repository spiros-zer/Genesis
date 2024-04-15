# Genesis

Modular character generation using Paragon's character assets.

## Goal
The ability to equip a Paragon's character weapon(s) to Manny and him inheriting the appropriate animations. This also includes sounds, fx, etc. 

## Project Layout
A dir named from the character (that the assets will be from) will contain a blueprint of the weapon(s) and in subdirs there will be the sounds, fx, etc.

## Workflow
### Character Rigs
So far, ~~Countess and Aurora~~ the humanoids of Paragon that I've checked, follow the UE4 Mannequin skeleton archetype - 3 spines, no finger metacarpals, no twists, etc. *ofc* there are exceptions to that due to weapon modifications, anatomy blah blah blah - **but** I will still go with making a retargetter for Manny who comes with a UE4 mannequin rtg anyways.
- Good IK Rig and good IK Retargetter gives very good animation.
- All anim_notifs for events, particles, emitters and whatnot carry over the retargetting 🥳🥳🥳

### Meshes
Since the animations should be bound to the weapon rather than the character if I want the **modularity**, I need to extract the weapon mesh from the character mesh. Now, Epic again does not want to make my life easier, but alas I found a workaround:
- ~~Make Static Mesh from the Skeletal Mesh this step is optional if a static mesh already exists~~ Locate the `SkeletalMesh` of the Paragon character.
- Open it and place the camera close to the character. This is very important for the next step, because all assets will be loaded and we will have the highest LOD.
- From the **Asset Actions** Export it and choose as save type `.gltf` - this is because the materials are not exported with other ways *plus most peeps online suggest using that*. ~~It is important to note that at some point the material quality was very low so in the export setting set the Default Material bake Size to 2048 x 2048.~~ Now you need to understand two things. ^1 The extracted model's materials will be bleak / not the same as inside Unreal; don't panic it should be like that and thus the materials extracted will **not** be the final ones, but just for visual help. ^2 When you reimport the model (more on that later) we will have to change its materials back to the src ones; so **don't** remove any src files.
- It is *blending* time. In Blender you need to import the `.gltf` file, delete the character mesh and appropriately modify the weapon. A more in-depth guide on this process for **one-handed weapons** can be found [here](). *Dual handed weapons coming soon*.
- Export from blender as `.fbx` and then import it in UE5.
- The process that follows when you import it back to UE, as it has already been mentioned, is **very important** and has its own [section]().

## FX
Since the Paragon assets were using the **Cascade Particle System**, I tried Unreal's plugin Cascade To Niagara Converter which did the job.**BUT** the converted FX have issues and some won't play at all 👹. I tried fixxing that - and again -, but due to the many unsolvable issues that piled up (see bellow) I will be doing Niagara only to the FX that are 100% no issue (warning or error) working. For the rest there is either use the *legacy system* or learn Niagara and do them from scratch.

### Issues
#### Warnings
- ✔ **The emitter is GPU and is using dynamic bounds mode. Please update the Emitter or System properties otherwise bounds may be incorrect** by following this (video)[https://www.youtube.com/watch?v=wZva4oxr-nc]> changing in the Emitter section *Calculate Bounds Mode* to *Fixed*.
- ❌ **Skipped converting cascade module "ParticleModuleVectorFieldLocal". Reason: failed to find converter script fot module**
- ❌ **Skipped converting cascade module "ParticleModuleVectorFieldBase". Reason: failed to find converter script fot module**
- ❌ **Skipped converting cascade module "ParticleModuleAttractorBase". Reason: failed to find converter script fot module**
- ❌ **Cascade light specified a spawn fraction but this mode is not supported by the asset converter**
#### Errors
- ❌ **Static variable is not set to a consistent value. Please ensure that all values are equal. Parameter: Particles.DynamicMaterialparameterChannelMask - Node: Map Set Pin: Particles.DynamicmaterialParamaterChannelMask**
