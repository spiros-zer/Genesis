<header>
  <h1>Genesis</h1>
  <p>Character generation using UE5 and Paragon assets</p>
  <section id="section-index">
    <h2>Index</h2>
    <ol>
      <li><a href="section-end-goal">End Goal</a></li>
      <li><a href="section-workflow">Workflow</a></li>
      <li><a href="section-findings">Findings</a></li>
    </ol>
  </section>
</header>

<body>
  <main>
    <section id="section-end-goal">
      <h2>End Goal</h2>
      <p>
      <strike>How to put it ... currently there is no goal. Will I create a huge animation pack for Manny, will I put them to some Paragon character? I am not really sure. <em>I think that huge animation pack for Manny is the best course, but how am I supposed to fdit all these in this repo here</em> 🤔</strike> A huge library of animations for Manny. All of them will have fx, sounds, anim_notifs setup. It will be categorized <em>per weapon of character</em>. For example a folder of Countess that will have her weapons and the animations executed with said weapons. 
      </p>
    </section>
    <section id="section-workflow">
      <h2>Workflow</h2>
      <p>
        On the repo should be <strong>only</strong> Manny animations. On base station there will be all the Paragon characters. In the future &mdash; once the characters' setup is completed &mdash; I will create a different repo to put them all inside.
      </p>
    </section>
    <section id="section-findings">
      <section id="section-findings--rigs">
        <h2>Character Rigs</h2>
        <p>
          <strike>So far, Countess and Aurora</strike> The humanoids of Paragon follow the UE4 Mannequin skeleton archetype &mdash; of 3 spines, no finger metacarpals, no twists, etc. <em>ofc</em> there are exceptions to that due to weapon modifications, anatomy blah blah blah &mdash;. <strong>But</strong> I will still go with making a retargetter for Manny who comes with a UE4 mannequin rtg anyways. 
        </p>
        <ul>
          <li>Good IK Rig and good IK Retargetter gives very good animation.</li>
          <li>All anim_notifs for events, particles, emitters and whatnot carry over the retargetting 🥳🥳🥳</li>
        </ul>
      </section>
      <section id="section-meshes">
        <h2>Meshes</h2>
        <p>So in order to make the animations bound to the weapon rather than the character, I need to extract the weapon mesh from the character mesh. Now, Epic again does not want to make my life easier, but alas I found a way to do it:</p>
          <ol>
            <li><strike>Make Static Mesh> from the Skeletal Mesh &mdash; this step is optional if a static mesh already exists.</strike> Locate the <code>Skeletal Mesh</code> of the character.</li>
            <li>From the <strong>Asset Actions Export</strong> it and choose as save type <code>.gltf</code> &mdash; the reason for going with <code>.gltf</code> is that the materials are not exported plus most peeps online suggest using that. <strike>It is important to note that at some point the material quality was very low so in the export setting set the <strong>Default Material bake Size to 2048 x 2048</strong>.</strike></li>
            <li>It is <em>Blender</em> time. In Blender you need to import the <code>.gltf</code> file, delete the character mesh and appropriately modify the weapon. A more in-depth guide on this process for <strong>one-handed weapons</strong> can be found <a href="">here</a>. Dual handed weapons coming soon.</li>
            <li>Export from blender as .fbx and then import it in UE5.</li>
          </ol>
        <p>
          The process that follows when you import it back to UE is very important and has its own <a href="">section</a>.
        </p>
      </section>
      <section id="section-fx">
        <h2>FX</h2>
        <p>
          <strike>Since the Paragon assets were using the <strong>Cascade Particle System</strong>, they had to be converted to <strong>Niagara Particle System</strong>. As I was told by my good friend <a href="">Stylianos</a>, Unreal has the amazing plugin Cascade To Niagara Converter which gets the job done, <strong>BUT</strong> the converted FX have issues and some won't play at all 😀. So we need to fix that <em>obviosuly</em></strike> Due to the many unsolvable issues that piled up (see bellow) I will be doing Niagara only to the FX that are 100% no issue (warning or error) working.
        </p>
        <h3>Warnings</h3>
        <h4>Emitter Properties</h4>
        <ul>
          <li>✔ <strong>The emitter is GPU and is using dynamic bounds mode. please update the Emitter or System properties otherwise bounds may be incorrect &mdash;</strong> by following this <a href="https://www.youtube.com/watch?v=wZva4oxr-nc">video</a> in the <em>Emitter</em> section change <em>Calculate Bounds Mode</em> to <em>Fixed</em>.</li>
          <li>❌ <strong>Skipped converting cascade module "ParticleModuleVectorFieldLocal". Reason: failed to find converter script fot module &mdash;</strong></li>
          <li>❌ <strong>Skipped converting cascade module "ParticleModuleVectorFieldBase". Reason: failed to find converter script fot module &mdash;</strong></li>
          <li>❌ <strong>Skipped converting cascade module "ParticleModuleAttractorBase". Reason: failed to find converter script fot module &mdash;</strong></li>
          <li>❌ <strong>Cascade light specified a spawn fraction but this mode is not supported by the asset converter &mdash;</strong></li>
        </ul>
        <h3>Errors</h3>
        <h4>Emitter Properties</h4>
        <ul>
          <li>❌ <strong>Static variable is not set to a consistent value. Please ensure that all values are equal. Parameter: Particles.DynamicMaterialparameterChannelMask - Node: Map Set Pin: Particles.DynamicmaterialParamaterChannelMask &mdash;</strong> by following this <a href="https://www.youtube.com/watch?v=wZva4oxr-nc">video</a> in the <em>Emitter</em> section change <em>Calculatye Bounds Mode</em> to <em>Fixed</em>.</li>
        </ul>
      </section>
    </section>
  </main>
</body>

