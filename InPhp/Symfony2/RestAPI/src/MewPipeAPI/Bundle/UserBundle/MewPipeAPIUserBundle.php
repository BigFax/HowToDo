<?php

namespace MewPipeAPI\Bundle\UserBundle;

use Symfony\Component\HttpKernel\Bundle\Bundle;

class MewPipeAPIUserBundle extends Bundle
{
	public function getParent()
    {
        return 'FOSUserBundle';
    }
}
