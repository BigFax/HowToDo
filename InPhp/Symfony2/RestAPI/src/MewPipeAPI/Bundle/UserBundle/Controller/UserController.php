<?php

namespace MewPipeAPI\Bundle\UserBundle\Controller;

use Symfony\Component\HttpFoundation\Request;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Method;
use FOS\RestBundle\Controller\FOSRestController;
use FOS\RestBundle\Controller\Annotations as Rest;

use MewPipeAPI\Bundle\UserBundle\Entity\User;

class UserController extends FOSRestController
{
	/**
     * @Route(name="get_user", requirements={"username": "[a-z0-9A-zéèà-]"})
     * @Method("GET")
     * @Rest\View
     */
    public function getUserAction($username)
    {
		$repository = $this->getDoctrine()
					   ->getManager()
					   ->getRepository('MewPipeAPIUserBundle:User');

		$user = $repository->findOneBy(array('username' => $username));
		
		if ($user === null) {
			return 'User[username='.$username.'] doesn\'t exist.';
    	}

	    return $user;
    }

    /**
     * @Route(name="get_users")
     * @Method("GET")
     * @Rest\View
     */
    public function getUsersAction()
    {
    	$repository = $this->getDoctrine()
						   ->getManager()
						   ->getRepository('MewPipeAPIUserBundle:User');

		$users = $repository->findAll();

		if ($users === null) {
			return 'Users not found.';
    	}

    	return array('users' => $users);

    	//$view = $this->view($users, 200);

	    //return $this->handleView($view);
    }

    /**
     * @Route(name="post_user")
     * @Method("POST")
     * @Rest\View
     */
    public function postUserAction()
    {
        $request = $this->getRequest();
        // Check
        // it
        // with
        // a
        // form !
        $user = new User();

        $user->setUsername($request->get('username'));
        $user->setEmail($request->get('email'));
        $user->setPlainPassword($request->get('password'));

        $em = $this->getDoctrine()->getManager();
        $em->persist($user);
        $em->flush();

        return true;
    }

    /**
     * @Route(name="put_user", requirements={"username": "[a-z0-9A-zéèà-]"})
     * @Method("PUT")
     * @Rest\View
     */
    public function putUserAction($username)
    {
        $request = $this->getRequest();
        // Check
        // it
        // with
        // a
        // form !

        $user = $this->getUserAction($username);
        $user->setUsername($request->get('newusername'));
        // Check if the attribute is sent if not, replace empty value in database because the attribute in form not sent

        $em = $this->getDoctrine()->getManager();
        $em->persist($user);
        $em->flush();

        return true;
    }

    // /**
    //  * @Route("/user/{username}", requirements={"username": "[a-z0-9A-zéèà-]"}, name="put_user")
    //  * @Method("PUT")
    //  * @Rest\View
    //  */
    // public function putUserAction($username)
    // {
    //     $repository = $this->getDoctrine()
    //                        ->getManager()
    //                        ->getRepository('MewPipeAPIUserBundle:User');

    //     $user = $repository->findOneBy(array('username' => $username));

    //     if ($user === null) {
    //         throw $this->createNotFoundException('User[name='.$username.'] inexistante.');
    //     }

    //     $em = $this->getDoctrine()->getManager();
    //     $em->remove($user);
    //     $em->flush();
    // }

	/**
     * @Route(name="delete_user", requirements={"username": "[a-z0-9A-zéèà-]"})
     * @Method("DELETE")
     * @Rest\View(statusCode=204)
     */
    public function deleteUserAction($username)
	{
		$user = $this->getUserAction($username);

    	$em = $this->getDoctrine()->getManager();
		$em->remove($user);
		$em->flush();
    }
}
