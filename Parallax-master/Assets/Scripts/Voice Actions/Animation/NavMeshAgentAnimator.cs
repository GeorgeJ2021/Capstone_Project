using UnityEngine;
using UnityEngine.AI;

[RequireComponent(typeof(Animator), typeof(NavMeshAgent))]
public class NavMeshAgentAnimator : MonoBehaviour
{
    private static int ANIMATOR_PARAM_WALK_SPEED =
       Animator.StringToHash("Blend");

    private Animator _animator;
    private NavMeshAgent _agent;

    private void Awake()
    {
        this._animator = this.GetComponent<Animator>();
        this._agent = this.GetComponent<NavMeshAgent>();
    }

    private void LateUpdate()
    {
        float speed = this._agent.velocity.magnitude;
        this._animator.SetFloat(ANIMATOR_PARAM_WALK_SPEED, speed);
    }
}
