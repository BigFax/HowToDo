<?php

namespace MewPipeAPI\Bundle\VideoBundle\Controller;

use Symfony\Component\HttpFoundation\Request;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Method;
use FOS\RestBundle\Controller\FOSRestController;
use FOS\RestBundle\Controller\Annotations as Rest;

use MewPipeAPI\Bundle\VideoBundle\Entity\Video;
use MewPipeAPI\Bundle\UserBundle\Entity\User;

class VideoController extends FOSRestController
{
	/**
     * @Route(name="get_video", requirements={"name": "[a-z0-9A-zéèà-]"})
     * @Method("GET")
     * @Rest\View
     */
    public function getVideoAction($name)
    {
		$repository = $this->getDoctrine()
					   ->getManager()
					   ->getRepository('MewPipeAPIVideoBundle:Video');

		$video = $repository->findOneBy(array('name' => $name));
		
		if ($video === null) {
			return 'Video[name='.$name.'] doesn\'t exist.';
    	}

	    return $video;
    }

    /**
     * @Route(name="post_video")
     * @Method("POST")
     * @Rest\View
     */
    public function postVideoAction()
    {
        $request = $this->getRequest();
        // Check
        // it
        // with
        // a
        // form !
        $video = new Video();
        $video->setName($request->get('name'));
        // Change that by user which is connected
        $repository = $this->getDoctrine()
					   ->getManager()
					   ->getRepository('MewPipeAPIUserBundle:User');

		$user = $repository->findOneBy(array('username' => 'admin'));

        $video->setUser($user);

        $em = $this->getDoctrine()->getManager();
        $em->persist($video);
        $em->flush();

        return true;
    }

    /**
     * @Route(name="put_video", requirements={"name": "[a-z0-9A-zéèà-]"})
     * @Method("PUT")
     * @Rest\View
     */
    public function putVideoAction($name)
    {
        $request = $this->getRequest();
        // Check
        // it
        // with
        // a
        // form !

        $video = $this->getVideoAction($name);
        $video->setName($request->get('newname'));
        // Check if the attribute is sent if not, replace empty value in database because the attribute in form not sent

        $em = $this->getDoctrine()->getManager();
        $em->persist($video);
        $em->flush();

        return true;
    }

	/**
     * @Route(name="delete_video", requirements={"name": "[a-z0-9A-zéèà-]"})
     * @Method("DELETE")
     * @Rest\View(statusCode=204)
     */
    public function deleteVideoAction($name)
	{
		$video = $this->getVideoAction($name);

    	$em = $this->getDoctrine()->getManager();
		$em->remove($video);
		$em->flush();
    }
}
