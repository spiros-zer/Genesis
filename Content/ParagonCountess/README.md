<header>
  <h1>Countess &#124; Integration</h1>
  <p>This is the process of integrating the Paragon asset Countess in a UE5 project and bringing it to astate of being able to be utilized in a game.</p>
</header>

<main>
  <section>
    <h2>
      Creating an IK Rig
    </h2>
    <p>
      <strong>Reasoning</strong> &mdash; creating a rig for the character was simply to be able to access the <strong>IK Rig Retargetter</strong> with UE5 Manny, because store bought animations are rigged on Manny, plus he could be used as a middle man to mix and match animations from multiple sources more efficiently.
      <h3>
        IK Rig Setup
      </h3>
      <p>Since I wanted max compatibility between Countess and Manny I made her IK Rig match his in the aspect of chains, solvers, and goals. Material used was for <a href="https://www.youtube.com/watch?v=xvHOamXuZDI&list=LL&index=1">making the chains</a>, <a href="https://docs.unrealengine.com/5.0/en-US/ik-rig-solvers-in-unreal-engine/">understanding the basics of solvers, goals and FullBody IK</a></p>
    </p>
    <h3>
      Important Notes
    </h3>
    <ul>
      <li>Follow Unreal's <strong>chain naming way</strong> to avoid tedious remapping of the ones that were automatically mapped wrong</li>
      <li><strong>Match Reference Poses</strong> &mdash; this is very important as issues with finger missplacement or other bones may be caused by this. The poses do not need to be precise but have the general geometry. <em>e.g.</em> Scale of characters should be the same, hands should be in the same pose (A or T) fingers should have general geometry same goes for legs.</li>
    </ul>
  </section>

  <section>
    <h2>
      Hair Problems
    </h2>
    <p>
      <strong>Reasoning</strong> &mdash; Countess' hair were penetrating the head mesh during animations of various intensity, but also in the idle position.
      <h3>
        Cloth re-painting
      </h3>
      <p>There was no reference of anyone having a problem with the asset in way (checked ue forums, reddit and google in general; no nothing). So by <strike>luck</strike> thinking a little outside of the box and experimenting, I discovered hair are treated as clothing. Ta-da! 💡 <a href="https://docs.unrealengine.com/5.2/en-US/clothing-tool-in-unreal-engine/">Unreal documentation on cloth painting</a> provided what I needed to fix it.</p>
    </p>
    <h3>
      Important Notes
    </h3>
    <ul>
      <li>Physics had <em>nothing</em> to do with it. In static mesh view by right clicking the hair mesh you could unling the clothing data and that would fix it, thus clothes clothes clothes.</li>
      <li>There were more hair meshes &mdash; when painting you will can see the clothing data in the Clothing tab &mdash; so I played around a bit with the brush and watching some animations to reach the result i wanted.</li>
      <li><strike>Unrelated to hair, but the <strong>ribbons of the swords were rigid </strong> af so I made them clothes, to behave as such.</strike> <em>didn't do that because original swords will be removed someway; until it is decided they will remain as is</em></li>
    </ul>
  </section>
</main>
