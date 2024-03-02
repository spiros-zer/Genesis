<section id="section-head">
  <h1>Paragon Countess</h1>
  <p>Setting up the Countess asset from Paragon.</p>
</section>

<section id="section-goal">
  <h2>Goal</h2>
  <p>The goal of this directory is to have the ability to make Countess' <em>persona</em> transferrable to another character. By persona I mean her animations, fx and voicelines. </p>
  <p>To achieve this, I set as ground rule that once <em>someone equips her weapons</em> they would inherit her personality i.e. animations, fx, etc.</p>
  <p>I also had to think if there would be a weapon progression system. For this I came up with the idea that the <em>cloth tied to her sword</em> mesh could act as an <em>ornamental knot</em> and depending on whixh knot you had equipped different stats could be provided &mdash; the ornamental knot would act as a secondary weapon like the <em>Dark Knight of BDO</em> &mdash;. Of course this also means she will have different sword meshes and everything ties up nicely once you think her multiple skins with different meshes for both the sowrds and the knots.</p>
</section>

<section id="section-workflow">
  <h2>Workflow</h2>
  <p>Bellow are the steps I took to achieve my goal:</p>
  <ol>
    <li>Conversion of <code>Skeletal Mesh</code> to <code>Static mesh</code> and extract is as <code>Countess.gltf</code></li>
    <li>Imported <code>Countess.gltf</code> to Blender and deleted everrything except one instance of her sword.</li>
    <li>Aligned the center of the hilt to the axis origin and set the center there as well &mdash; this step is very important as the part which you have defined as the center will be the part that will connect in UE. This can be workaround with bones as well.</li>
    <li>Added bone for the hilt and the blade. This is because I can add a <code>socket</code> to the hilt bone in UE to attach the knot precisely.</li>
    <li>Cleaned up the materials I didn't need.</li>
    <li>Exported as <code>CountessSword_Armature.fbx</code> and imported to UE as <code>Skeletal Mesh</code>. <strong>Note</strong> that the bones may look weird &mdash; like huge spheres &mdash;, but this can be fixed by changing the bone draw size since it's purely visual.</li>
    <li>I then use the <code>AttachComponentToComponent</code> node to attach the sword to the socket of the skeletal mesh of my character as I see fit.</li>
  </ol>
</section>

<section id="section-current">
  <h2>Current State</h2>
  </section>